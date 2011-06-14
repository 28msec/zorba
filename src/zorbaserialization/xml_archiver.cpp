/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include "zorbaserialization/xml_archiver.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba{
  namespace serialization{

XmlArchiver::XmlArchiver(std::istream *is) : Archiver(false)
{
  //open archiver for input
  this->is = is;
  this->os = NULL;
  read_tag_level = 0;
  is_compound_field_without_children = false;

  //read the top tag
  char  c = 0;
  
read_tag:
  while(c != '<')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
  }

  is->read(&c, 1);
  if(c == '?')//skip pi
  {
    skip_tag();
    goto read_tag;
  }
  if(c == '!')//skip comment
  {
    skip_comment_tag();
    goto read_tag;
  }
  if(!read_root_tag(c))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
  }
  read_tag_level++;
}

XmlArchiver::XmlArchiver(std::ostream *os) : Archiver(true)
{
  //open archiver for output
  this->is = NULL;
  this->os = os;

  memset(indent_spaces, ' ', sizeof(indent_spaces)-1);
  indent_spaces[sizeof(indent_spaces)-1] = 0;
  indent_off = sizeof(indent_spaces)-1;
}

void XmlArchiver::serialize_out()
{
  if(!os)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION);
  }

  prepare_serialize_out();

  write_string("<?xml version=\"1.0\"?>\n");
  write_string("<zorba_archive archive_name=\"");
  encode_string(archive_name.c_str());
  write_string("\" ");
  write_string("archive_info=\"");
  encode_string(archive_info.c_str());
  write_string("\" ");
  *os << "archive_version=\"" << archive_version << "\" ";
  *os << "nr_ids=\"" << nr_ids << "\" >" << std::endl;
  serialize_compound_fields(out_fields);
  write_string("</zorba_archive>\n");

}

void XmlArchiver::serialize_compound_fields(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  char strtemp[100];
  while(current_field)
  {
    write_string(indent_off >= 0 ? indent_spaces+indent_off : indent_spaces);
    write_string("<obj_field is_simple=\"");
    write_string(current_field->is_simple ? "true" : "false");
    write_string("\" ");
    write_string("type=\"");
    write_string(current_field->type);
    write_string("\" ");
    write_string("version=\"");
    sprintf(strtemp, "%d", current_field->version);
    write_string(strtemp);
    write_string("\" ");
    write_string("field_treat=\"");
    write_string(get_field_treat_string(current_field->field_treat));
    write_string("\" ");
    write_string("referencing=\"");
    sprintf(strtemp, "%d", current_field->referencing);
    write_string(strtemp);
    write_string("\" ");
    write_string("id=\"");
    sprintf(strtemp, "%d", current_field->id);
    write_string(strtemp);
    write_string("\" ");
    write_string("is_class=\"");
    write_string(current_field->is_class ? "true" : "false");
    write_string("\" ");
    write_string("value=\"");
    encode_string(current_field->value);
    write_string("\" ");

    if(current_field->is_simple || 
      (current_field->field_treat == ARCHIVE_FIELD_IS_REFERENCING) ||
      (current_field->first_child == NULL))
    {
      write_string("/>\n");
    }
    else
    {
      write_string(">\n");
      indent_off -= 2;
      serialize_compound_fields(current_field);
      indent_off += 2;
      write_string(indent_off >= 0 ? indent_spaces+indent_off : indent_spaces);
      write_string("</obj_field>\n");
    }
    current_field = current_field->next;
  }
}

void XmlArchiver::encode_string(const char *value)
{
  if(!value)
    return;
  while(*value)
  {
    switch(*value)
    {
    case '\"': write_string("&quot;");break;
    case '&': write_string("&amp;");break;
    default: os->write(value, 1);break;
    }
    value++;
  }
}

void XmlArchiver::write_string(const char *str)
{
  os->write(str, (std::streamsize)strlen(str));
}

const char *XmlArchiver::get_field_treat_string(enum ArchiveFieldTreat field_treat)
{
  switch(field_treat)
  {
  case ARCHIVE_FIELD_NORMAL : return "ARCHIVE_FIELD_NORMAL"; break;
  case ARCHIVE_FIELD_IS_PTR : return "ARCHIVE_FIELD_IS_PTR"; break;
  case ARCHIVE_FIELD_IS_NULL : return "ARCHIVE_FIELD_IS_NULL"; break;
  case ARCHIVE_FIELD_IS_BASECLASS : return "ARCHIVE_FIELD_IS_BASECLASS"; break;
  case ARCHIVE_FIELD_IS_REFERENCING : return "ARCHIVE_FIELD_IS_REFERENCING"; break;
  }
  return NULL;
}


////////////reading archive

bool XmlArchiver::read_next_field_impl( char **type, 
                              std::string *value,
                              int *id, 
                              int *version, 
                              bool *is_simple, 
                              bool *is_class,
                              enum ArchiveFieldTreat *field_treat,
                              int *referencing)
{
  if(!is)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION);
  }

  *type = NULL;
  *id = -1; 
  *version = -1; 
  *is_simple = false; 
  *is_class = false,
  *field_treat = (enum ArchiveFieldTreat)-1;
  *referencing = -1;

  if(is_compound_field_without_children)
  {
    return false;
  }

  char  c = 0;
  
read_tag:
  while(c != '<')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      return false;
    }
  }

  is->read(&c, 1);
  if(c == '?')//skip pi
  {
    skip_tag();
    goto read_tag;
  }
  if(c == '!')//skip comment
  {
    skip_comment_tag();
    goto read_tag;
  }
  if(read_tag_level == 0)
  {
    if(!read_root_tag(c))
      return false;
    read_tag_level++;
    goto read_tag;
  }
  if(!match_string(c, "obj_field"))
  {
    return false;
  }

  char  attrib_name[100];
  char  attrib_value[100];
  int   attr_index = 0;

  while(read_attrib_name(attrib_name))
  {
//    write_string("<obj_field is_simple=\"" << (current_field->is_simple ? "true" : "false") << "\" "
//        <<"type=\"" << current_field->type << "\" "
//        <<"version=\"" << current_field->version << "\" "
//        <<"field_treat=\"" << get_field_treat_string(current_field->field_treat) << "\" "
//        <<"referencing=\"" << current_field->referencing << "\" "
//        <<"id=\"" << current_field->id << "\" "
//        <<"is_class=\"" << current_field->is_class << "\" "
//        <<"value=\"" ;//<< current_field->value ? current_field->value : "" << "\" ";
process_attr:
    switch(attr_index)
    {
    case 0:
      if(!strcmp(attrib_name, "is_simple"))
      {
        read_attrib_value(attrib_value);
        if(!strcmp(attrib_value, "true"))
          *is_simple = true;
        else if(!strcmp(attrib_value, "false"))
          *is_simple = false;
        else
        {
          return false;
        }
        attr_index++;
        break;
      }
    case 1:
      if(!strcmp(attrib_name, "type"))
      {
        read_attrib_value(field_type);
        *type = field_type;
        attr_index++;
        break;
      }
    case 2:
      if(!strcmp(attrib_name, "version"))
      {
        read_attrib_value(attrib_value);
        *version = atoi(attrib_value);
        attr_index++;
        break;
      }
    case 3:
      if(!strcmp(attrib_name, "field_treat"))
      {
        read_attrib_value(attrib_value);
        if(!strcmp(attrib_value, "ARCHIVE_FIELD_NORMAL"))
          *field_treat = ARCHIVE_FIELD_NORMAL;
        else if(!strcmp(attrib_value, "ARCHIVE_FIELD_IS_PTR"))
          *field_treat = ARCHIVE_FIELD_IS_PTR;
        else if(!strcmp(attrib_value, "ARCHIVE_FIELD_IS_NULL"))
          *field_treat = ARCHIVE_FIELD_IS_NULL;
        else if(!strcmp(attrib_value, "ARCHIVE_FIELD_IS_BASECLASS"))
          *field_treat = ARCHIVE_FIELD_IS_BASECLASS;
        else if(!strcmp(attrib_value, "ARCHIVE_FIELD_IS_REFERENCING"))
          *field_treat = ARCHIVE_FIELD_IS_REFERENCING;
        else
        {
          return false;
        }
        attr_index++;
        break;
      }
    case 4:
      if(!strcmp(attrib_name, "referencing"))
      {
        read_attrib_value(attrib_value);
        *referencing = atoi(attrib_value);
        attr_index++;
        break;
      }
    case 5:
      if(!strcmp(attrib_name, "id"))
      {
        read_attrib_value(attrib_value);
        last_id = *id = atoi(attrib_value);
        attr_index++;
        break;
      }
    case 6:
      if(!strcmp(attrib_name, "is_class"))
      {
        read_attrib_value(attrib_value);
        if(!strcmp(attrib_value, "true"))
          *is_class = true;
        else if(!strcmp(attrib_value, "false"))
          *is_class = false;
        else
        {
          return false;
        }
        attr_index++;
        break;
      }
    case 7:
      if(!strcmp(attrib_name, "value"))
      {
        read_attrib_value(value);
        attr_index++;
        break;
      }
    default:
      if(!attr_index)
      {
        //unrecognized attribute name
        return false;
      }
      attr_index = 0;
      goto process_attr;
    };
  }

  is_compound_field_without_children = false;
  if(!strcmp(attrib_name, "/"))//empty tag
  {
    if(!*is_simple && (*field_treat != ARCHIVE_FIELD_IS_REFERENCING))
      is_compound_field_without_children = true;
  }
  else
    read_tag_level++;
  //'>' is already read
  return true;
}



bool XmlArchiver::read_root_tag(char c)
{
  if(!match_string(c, "zorba_archive"))
  {
    return false;
  }

//  write_string("<zorba_archive archive_name=\"";
//  encode_string(archive_name.c_str());
//  write_string("\" ";
//  write_string("archive_info=\"";
//  encode_string(archive_info.c_str());
//  write_string("\" ";
//  write_string("archive_version=\"" << archive_version << "\" >";
  char  attrib_name[100];
  char  attrib_value[100];

  while(read_attrib_name(attrib_name))
  {
    if(!strcmp(attrib_name, "archive_name"))
    {
      read_attrib_value(&archive_name);
    }
    else if(!strcmp(attrib_name, "archive_info"))
    {
      read_attrib_value(&archive_info);
    }
    else if(!strcmp(attrib_name, "archive_version"))
    {
      read_attrib_value(attrib_value);
      archive_version = atoi(attrib_value);
    }
    else if(!strcmp(attrib_name, "nr_ids"))
    {
      read_attrib_value(attrib_value);
      nr_ids = atoi(attrib_value);
    }
  }
  root_tag_is_read();
  return true;
}

void XmlArchiver::read_end_current_level_impl()
{
  if(is_compound_field_without_children)
  {
    is_compound_field_without_children = false;
    return;
  }

  read_tag_level--;
  char  c = 0;
read_tag:
  while(c != '<')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
  }

  is->read(&c, 1);
  if(c == '?')//skip pi
  {
    skip_tag();
    goto read_tag;
  }
  if(c == '!')//skip comment
  {
    skip_tag();
    goto read_tag;
  }
  if(read_tag_level)
  {
    if(!match_string(c, "/obj_field"))
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(last_id));
    }
  }
  else
  {
    if(!match_string(c, "/zorba_archive"))
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(last_id));
    }
  }

  return;
}

bool XmlArchiver::match_string(char c, const char *match)
{
  if(match[0] != c)
    return false;
  match++;
  while(*match)
  {
    is->read(&c, 1);
    if(c != *match)
      return false;
    match++;
  }
  is->read(&c, 1);
  if(c == '>')
    has_attributes = false;
  else
    has_attributes = true;
  return true;
}

bool XmlArchiver::read_attrib_name(char *attrib_name)
{
  char c;
  if(!has_attributes)
    return false;
read_name:
  do
  {
    is->read(&c, 1);
    if(c == 0)
    {
      return false;
    }
  }
  while((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r'));
  if(c == '>')
    return false;
  if(c == '/')
  {
    strcpy(attrib_name, "/");
    goto read_name;
  }
  *attrib_name = c;
  attrib_name++;
  while(1)
  {
    is->read(&c, 1);
    if(c == 0)
    {
      return false;
    }
    if(c == '>')
      return false;
    if((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r') || (c == '='))
      break;
    *attrib_name = c;
    attrib_name++;
  }
  *attrib_name = 0;
  while(c != '=')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      return false;
    }
  }
  return true;
}

void XmlArchiver::read_attrib_value(char *attrib_value)
{
  char c = 0;
  while(c!='\"')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
  }
  c = 0;
  while(1)
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
    if(c == '\"')
      break;
    //case '\"': write_string("&quot;";break;
    //case '&': write_string("&amp;";break;
    //decode char ref
    if(c == '&')
    {
      bool  append_c = true;
      is->read(&c, 1);
      if(c=='q')
      {
        is->read(&c, 1);
        if(c == 'u')
        {
          is->read(&c, 1);
          if(c == 'o')
          {
            is->read(&c, 1);
            if(c == 't')
            {
              is->read(&c, 1);
              if(c == ';')
              {
                strcpy(attrib_value, "\"");
                append_c = false;
              }
              else
              {
                strcpy(attrib_value, "&quot");
              }
            }
            else
            {
              strcpy(attrib_value, "&quo");
            }
          }
          else
          {
            strcpy(attrib_value, "&qu");
          }
        }
        else
        {
          strcpy(attrib_value, "&q");
        }
      }
      else if(c == 'a')
      {
        is->read(&c, 1);
        if(c == 'm')
        {
          is->read(&c, 1);
          if(c == 'p')
          {
            is->read(&c, 1);
            if(c == ';')
            {
              strcpy(attrib_value, "&");
              append_c = false;
            }
            else
            {
              strcpy(attrib_value, "&amp");
            }
          }
          else
          {
            strcpy(attrib_value, "&am");
          }
        }
        else
        {
          strcpy(attrib_value, "&a");
        }
      }
      else
      {
        attrib_value[0] = '&';
        attrib_value[1] = 0;
      }
      attrib_value += strlen(attrib_value);
      if(c == '\"')
        break;
      if(!append_c)
        continue;
    }
    *attrib_value = c;
    attrib_value++;
  }
  *attrib_value = 0;
}

void XmlArchiver::read_attrib_value(std::string *attrib_value)
{
  char c = 0;
  while(c!='\"')
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
  }
  c = 0;
  while(1)
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
    if(c == '\"')
      break;
    if(c == '&')
    {
      bool  append_c = true;
      is->read(&c, 1);
      if(c=='q')
      {
        is->read(&c, 1);
        if(c == 'u')
        {
          is->read(&c, 1);
          if(c == 'o')
          {
            is->read(&c, 1);
            if(c == 't')
            {
              is->read(&c, 1);
              if(c == ';')
              {
                *attrib_value += "\"";
                append_c = false;
              }
              else
              {
                *attrib_value += "&quot";
              }
            }
            else
            {
              *attrib_value += "&quo";
            }
          }
          else
          {
            *attrib_value += "&qu";
          }
        }
        else
        {
          *attrib_value += "&q";
        }
      }
      else if(c == 'a')
      {
        is->read(&c, 1);
        if(c == 'm')
        {
          is->read(&c, 1);
          if(c == 'p')
          {
            is->read(&c, 1);
            if(c == ';')
            {
              *attrib_value += "&";
              append_c = false;
            }
            else
            {
              *attrib_value += "&amp";
            }
          }
          else
          {
            *attrib_value += "&am";
          }
        }
        else
        {
          *attrib_value += "&a";
        }
      }
      else
      {
        *attrib_value += '&';
      }
      if(c == '\"')
        break;
      if(!append_c)
        continue;
    }
    *attrib_value += c;
  }
}

void XmlArchiver::skip_tag()
{
  std::string   temp_val;
  char  attrib_name[100];

  char c = 0;
  while((c != ' ') && (c != '\t') && (c != '\n') && (c != '\r') && (c != '>'))
  {
    is->read(&c, 1);
    if(c == 0)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
    }
  }
  if(c == '>')
    return;
  has_attributes = true;
  while(read_attrib_name(attrib_name))
  {
    read_attrib_value(&temp_val);
  }
}

void XmlArchiver::skip_comment_tag()
{
  char c;
  is->read(&c, 1);
  if(c == '[')
  {
    int index = 0;
    while(1)
    {
      is->read(&c, 1);
      if(c == 0)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
      }
      switch(c)
      {
      case ']':
        index++;
        break;
      case '>':
        if(index >= 2)
            return;
      default:
        index = 0;
        break;
      }
    }
    return;
  }
  else if(c == '-')
  {//skip comment
    int index = 0;
    while(1)
    {
      is->read(&c, 1);
      if(c == 0)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
      }
      switch(c)
      {
      case '-':
        index++;
        break;
      case '>':
        if(index >= 2)
            return;
      default:
        index = 0;
        break;
      }
    }
  }
  else
  {
    //generic skip
    while(c != '>')
    {
      is->read(&c, 1);
      if(c == 0)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE);
      }
    }
  }
}

}}
/* vim:set et sw=2 ts=2: */
