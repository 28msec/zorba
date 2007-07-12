/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: ft_selection.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FT_SELECTION_H
#define XQP_FT_SELECTION_H

#include "values.h"


/*______________________________________________________________________
|  
|	Interface definition for search algebra objects
|	corresponding to FTSelection expressions.
|
|	Refer to: "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|
|_______________________________________________________________________*/


namespace xqp {


/*______________________________________________________________________
|  
|	FTWords
|
|	'target' must be an element, text, processing instruction, 
|	or comment node with a non-empty parent property.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/

class ft_words : public ft_selection
{
public:
	enum ft_anyall_option {
		any,
		any_word,
		all,
		all_words,
		phrase
	};

protected:
	std::vector<std::string> word_v;
	ft_anyall_option options;

public:
	ft_words(
		std::vector<std::string> const&,
		enum ft_anyall_option);

	~ft_words() {}

};


/*______________________________________________________________________
|  
|	FTOr
|_______________________________________________________________________*/

class ft_or : public ft_selection
{
protected:
	std::vector<ft_selection> v;

public:
	ft_or() {}
	~ft_or() {}

public:
	void add(ft_selection const&);
	uint32_t size() const;

};


/*______________________________________________________________________
|  
|	FTAnd
|_______________________________________________________________________*/

class ft_and : public ft_selection
{
protected:
	std::vector<ft_selection> v;

public:
	ft_and() {}
	~ft_and() {}

public:
	void add(ft_selection const&);
	uint32_t size() const;

};


/*______________________________________________________________________
|  
|	FTMildNot
|_______________________________________________________________________*/

class ft_mildnot : public ft_selection
{
protected:
	std::vector<ft_selection> v;

public:
	ft_mildnot() {}
	~ft_mildnot() {}

public:
	void add(ft_selection const&);
	uint32_t size() const;

};


/*______________________________________________________________________
|  
|	FTUnaryNot
|_______________________________________________________________________*/

class ft_unarynot : public ft_selection
{
protected:
	ft_selection v;

public:
	ft_unarynot(ft_selection const&) {}
	~ft_unarynot() {}

};



} /* namespace xqp */
#endif /* XQP_FT_SELECITON_H */

