#ifndef ZORBA_ZORBA_ENGINE_SINGLETHREAD_API_H
#define ZORBA_ZORBA_ENGINE_SINGLETHREAD_API_H

#include <zorba/zorba_baseengine_api.h>

namespace xqp{

  // TODO move into api_shared_types.h
  class ZorbaSingleThread;
  typedef rchandle<ZorbaSingleThread> ZorbaSingleThread_t;

  /** 
   * Class description...
   *
   */
  class ZorbaSingleThread : public virtual ZorbaBaseEngine
  {
    public:
      static ZorbaSingleThread_t 
      getInstance();

      /** \brief Executes a given %XQuery and prints the XML serialization of the result
       *         to the given output stream.
       *
       * A more elaborate description...
       *
       * @param xquery to execute
       *
       * @param os the output stream on which the result should be printed.
       *
       * @returns <code>true</code> if the query was executed successfully, <code>false</code> otherwise.
       *
       * \throws ZorbaException if the ThrowException Mode (see ZorbaAlertsManager::setThrowExceptionsMode)
       *         is set to <code>true</code>.
       *
       */
      static bool
      execute(xqp_string xquery, std::ostream &os);

    public:
      virtual ~ZorbaSingleThread();
  };
  
} /* namespace xqp */
#endif
