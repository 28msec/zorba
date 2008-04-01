#ifndef ZORBA_COMPILER_API_H
#define ZORBA_COMPILER_API_H

#include <memory>
#include "zorbatypes/representations.h"

#include "common/shared_types.h"

namespace zorba {

  class XQueryCompiler {
    public:
      XQueryCompiler(CompilerCB*  aCompilerCB);

      virtual ~XQueryCompiler();

      PlanIter_t
      compile(std::istream& aXQuery, const xqpString & aFileName = "");

    protected:
      parsenode_t
      parse(std::istream& aXQuery, const xqpString & aFileName = "");

      expr_t
      normalize(parsenode_t);

      expr_t
      optimize(expr_t lExpr);

      CompilerCB* theCompilerCB;
  };

  class XQueryCompilerSubsystem {
    public:
      XQueryCompilerSubsystem();
      virtual ~XQueryCompilerSubsystem() throw ();

      virtual Rewriter *getDefaultOptimizingRewriter() = 0;

    private:
      static std::auto_ptr<XQueryCompilerSubsystem> create();
      friend class GlobalEnvironment;
  };

} /* namespace zorba */
#endif /* ZORBA_COMPILER_API_H */
/* vim:set ts=2 sw=2: */
