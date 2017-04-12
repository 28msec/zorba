# Memory Management

## Introduction

The Zorba processor
allows you to customize various functionality
via its C++ API.
As expected,
this is done by providing C++ classes
that you derive from
and provide your own implementations
of virtual functions.
You then provide Zorba with instances of your derived classes.

However,
there are two problems:
one general
and one that's Windows-specific.

## The General Problem

The general problem is instance ownership,
i.e.,
after you provide Zorba with an instance of one of your derived classes,
should it be destroyed by Zorba?

For example,
suppose the API for the full-text `Stemmer` were this:

```cpp
// NOTE: THIS IS NOT THE ACTUAL API -- IT'S A "WHAT IF" API

class Stemmer {
public:
  virtual ~Stemmer();
  // ...
};

class StemmerProvider {
public:
  // ...
  Stemmer* getStemmer( locale::iso639_1::type lang ) const = 0;
};
```

and that you implemented it like this:

```cpp
class MyStemmerProvider : public StemmerProvider {
public:
  Stemmer* getStemmer( locale::iso639_1::type lang ) const;
};

Stemmer* MyStemmerProvider::getStemmer( locale::iso639_1::type lang ) const {
  MyStemmer stemmer;
  return &stemmer;
}
```

Assume that your stemmer is used for all languages
and that it maintains no state.
For efficiency,
you could therefore use a singleton instance of it.
The problem is that Zorba can't tell the difference between
a non-singleton (dynamically allocated) instance
and a singleton (statically allocated) instance,
i.e.,
whether to call \c delete on it or not.
(In C++, there is no built-in way
to determine whether a pointer points to an object
that is statically allocated or was dynamically allocated.)

## The Windows-Specific Problem

A further complication is that,
on the Windows platform,
there is an issue with dynamically allocating instances in your executable
and deallocating them in a library
(or vice versa).
This has to do with the Windows C Runtime Library
that's used by the executable and library:
if they don't match
and you dynamically allocate an instance in your executable
and it's deallocated in the library
(or vice versa),
your program will crash.

The only way to avoid this problem
is to ensure that all instances
that are dynamically allocated in your executable
are also deallocated in your executable;
and the same goes for the library.

## The Solution to Both Problems

A solution to both problems
is to replace what would have been a call to \c delete
with a call to a \c virtual member function \c destroy().
The API for the full-text \c Stemmer would now be
(and actually is):

```cpp
class Stemmer {
public:
  typedef /* implementation-defined */ ptr;
  virtual void destroy() const = 0;
  // ...
protected:
  virtual ~Stemmer();
};

class StemmerProvider {
public:
  // ...
  Stemmer::ptr getStemmer( locale::iso639_1::type lang ) const = 0;
};
```

The changes are:

  * A new `ptr` type that is to be used in the place of a native C++ pointer.
    It uses the relatively new C++ `std::unique_ptr` class
    and specifies a custom deleter that calls `destroy()`
    rather than `delete`.
    (If your C++ implementation doesn't have `unique_ptr`,
    Zorba provides its own.)
  * A new pure `virtual` `destroy()` member function.
  * The destructor has been made `protected` to prevent destruction by calling `delete` from outside the class.

If you now implemented your stemmer like this:

```cpp
class MyStemmer {
public:
  void destroy();
  // ...
private:
  MyStemmer();
  friend class MyStemmerProvider; // only it can create instances
};

void MyStemmer::destroy() const {
  // Do nothing since our stemmer is statically allocated.
}

class MyStemmerProvider : public StemmerProvider {
public:
  Stemmer::ptr getStemmer( locale::iso639_1::type lang ) const;
};

Stemmer::ptr MyStemmerProvider::getStemmer( locale::iso639_1::type lang ) const {
  static MyStemmer stemmer;
  return Stemmer::ptr( &stemmer );
}
```

then it would work for a statically allocated instance of your stemmer.
On the other hand,
if your `StemmerProvider` dynamically allocates instances,
then your implementation should be like this:

```cpp
void MyStemmer::destroy() const {
  delete this;
}

Stemmer::ptr MyStemmerProvider::getStemmer( locale::iso639_1::type lang ) const {
  return Stemmer::ptr( new MyStemmer );
}
```
