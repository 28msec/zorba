#ifndef ZORBA_PATH_H
#define ZORBA_PATH_H

#include <string>
#include <iostream>

namespace zorba {

class filesystem_path {
protected:
  std::string path;

public:
  const std::string &get_path () const { return path; }
  const char *c_str () { return path.c_str (); }
  operator const std::string & () const { return path; }
  filesystem_path (const std::string &path_) : path (path_) {}
  filesystem_path (const filesystem_path &base, const filesystem_path &rel) {
    if (rel.is_absolute ())
      *this = rel;
    else
      *this = base.get_path () + get_path_separator () + rel.get_path ();
  }
  // from current dir
  filesystem_path ();
  filesystem_path &operator = (const std::string &p_)
  { path = p_; return *this; }

  bool is_absolute () const;
  void resolve_relative ();

  static const char *get_path_separator ();
};

inline std::ostream &operator<< (std::ostream &os, const filesystem_path &p)
{ os << p.get_path (); return os; }

}

#endif
