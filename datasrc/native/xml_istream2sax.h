/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_istream2sax.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_XML_ISTREAM2SAX_H
#define XQP_XML_ISTREAM2SAX_H

namespace xqp {

class xml_istream2sax
{

	/**
	 * Report element to handler.
	 *
	 * @param initial node information byte for element
	 * @throws IOException on error reading from stream
	 * @throw xqpexception on error in processing XML data
	 */
	void reportElement(int initial);
	
	/**
	 * Report character data.
	 *
	 * @param ch array supplying character data
	 * @param start starting offset in array
	 * @param length number of characters
	 * @throw xqpexception on processing error
	 */
	void reportText(char* ch, int start, int length)
		throw (xqpexception);

	/**
	 * Report CDATA section.
	 *
	 * @param ch array supplying character data
	 * @param start starting offset in array
	 * @param length number of characters
	 * @throw xqpexception on processing error
	 */
	void reportCDATA(char* ch, int start, int length)
		throw (xqpexception);
    
	/**
	 * Report processing instruction.
	 *
	 * @param target processing instruction target
	 * @param data processing instruction data
	 * @throw xqpexception on processing error
	 */
	void reportProcessingInstruction(std::string const& target,
																	 std::string cosnt& data)
		throw (xqpexception);

	/**
	 * Report comment.
	 *
	 * @param ch array supplying character data
	 * @param start starting offset in array
	 * @param length number of characters
	 * @throw xqpexception on processing error
	 */
	void reportComment(char* ch, int start, int length)
		throw (xqpexception);
    
	/**
   * Report document type information.
   *
   * @param name element name
   * @param pubid public id
   * @param sysid system id
   * @throw xqpexception on processing error
   */
	void reportDocType(std::string const& name,
										 std::string const& pubid,
										 std::string const& sysid)
		throw (xqpexception);
    
	/**
	 * Report notation information.
	 *
	 * @param name notation name
	 * @param pubid public id
 	 * @param sysid system id
 	 * @throw xqpexception on processing error
	 */
	void reportNotation(std::string const& name,
											std::string const& pubid,
											std::string const& sysid)
		throw (xqpexception);

	/**
	 * Report unparsed entity information.
	 *
	 * @param name entity name
	 * @param pubid public id
	 * @param sysid system id
	 * @param notation notation name
	 * @throw xqpexception on processing error
	 */
	void reportUnparsedEntity(std::string const& name,
														std::string const& pubid,
														std::string const& sysid,
														std::string const& notation)
		throw (xqpexception);
    
	/**
	 * Report skipped entity information.
	 *
	 * @param name entity name
	 * @throw xqpexception on processing error
	 */
	void reportSkippedEntity(std::string const& name)
		throw (xqpexception);
    
	/**
	 * Report element declaration information.
	 *
	 * @param name element name
	 * @param model content model
	 * @throw xqpexception on processing error
	 */
	void reportElementDecl(std::string const& name,
												 std::string const& model)
		throw (xqpexception);
    
	/**
	 * Report attribute declaration information.
	 *
	 * @param ename owning element name
	 * @param aname attribute name
	 * @param type attribute type
	 * @param deftype defaulting type
	 * @param dflt default value
	 * @throw xqpexception on processing error
	 */
	void reportAttributeDecl(std::string const& ename,
													 std::string const& aname,
													 std::string const& type,
													 std::string const& deftype,
													 std::string const& dflt)
		throw (xqpexception);
    
	/**
	 * Report external entity declaration information.
	 *
	 * @param name external entity name
	 * @param pubid public id
	 * @param sysid system id
	 * @throw xqpexception on processing error
	 */
	void reportExternalEntityDecl(std::string const& name,
																std::string const& pubid,
																std::string const& sysid)
		throw (xqpexception);


	/**
	 * Read children of node from stream.
	 *
	 * @throw xqpexception on error in processing XML data
	 */
	void readChildren()
		throw (xqpexception);


	/**
	 * Read document from stream.
	 *
	 * @throw xqpexception on error in processing XML data
	 */
	void readDocument()
		throw (xqpexception);



};


}	/* namespace xqp */
#endif	/* XQP_XML_ISTREAM2SAX_H */
