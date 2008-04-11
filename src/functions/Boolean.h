/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef ZORBA_BOOLEAN_H
#define ZORBA_BOOLEAN_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba
{
  class GenericOpComparison : public function
  {
  public:
    GenericOpComparison ( const signature&);
    
    virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;
    
  protected:
    virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& ) const = 0;
  };

  class ValueOpComparison : public GenericOpComparison {
  public:
    ValueOpComparison (const signature &sig) : GenericOpComparison (sig) {}
    xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  };
  
  /*----------------------------------- generic comparison --------------------------------*/
  class op_equal : public GenericOpComparison
  {
  public:
    op_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_not_equal : public GenericOpComparison
  {
  public:
    op_not_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_greater : public GenericOpComparison
  {
  public:
    op_greater( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_greater_equal : public GenericOpComparison
  {
  public:
    op_greater_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_less : public GenericOpComparison
  {
  public:
    op_less( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_less_equal : public GenericOpComparison
  {
  public:
    op_less_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  /*----------------------------------- value comparison --------------------------------*/
  class op_value_equal : public ValueOpComparison
  {
  public:
    op_value_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_value_not_equal : public ValueOpComparison
  {
  public:
    op_value_not_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_value_greater : public ValueOpComparison
  {
  public:
    op_value_greater( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_value_greater_equal : public ValueOpComparison
  {
  public:
    op_value_greater_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_value_less : public ValueOpComparison
  {
  public:
    op_value_less( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  
  class op_value_less_equal : public ValueOpComparison
  {
  public:
    op_value_less_equal( const signature&);
  protected:
    virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
  };
  

  /*-------------------------- Node Comparison -------------------------------------------*/

  class op_is_same_node : public function
  {
  public:
    op_is_same_node( const signature& aSig) : function(aSig) {}
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_node_before : public function
  {
  public:
    op_node_before( const signature& aSig) : function(aSig) {}
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_node_after : public function
  {
  public:
    op_node_after( const signature& aSig) : function(aSig) {}
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  /*-------------------------- Logical Expressions ---------------------------------------*/
  class op_and : public function
  {
    public:
      op_and ( const signature& );
      
    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_or : public function
  {
    public:
      op_or ( const signature& );
      
    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  // 9 Functions and Operators on Boolean Values
  // 9.1.1 fn:true
  class fn_true : public function
  {
    public:
      fn_true ( const signature& );
      
    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_true */
  
  // 9.1.2 fn:false
  class fn_false : public function
  {
    public:
      fn_false ( const signature& );
      
    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_false */
  
  // 9.3.1 fn:not
  class fn_not : public function
  {
  public:
    fn_not ( const signature& );
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 15 Functions and Operators on Sequences
  // 15.1.1 fn:boolean
  class fn_boolean : public function
  {
    public:
      fn_boolean ( const signature& );

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_false */
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
