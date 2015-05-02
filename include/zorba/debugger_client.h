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
#ifndef ZORBA_DEBUGGER_CLIENT_H
#define ZORBA_DEBUGGER_CLIENT_H

#include <map>
#include <list>
#include <vector>

#include <zorba/api_shared_types.h>
#include <zorba/debugger_event_handler.h>
#include <zorba/query_location.h>

namespace zorba {

  /**
   * Representation of the runtime stack frame.
   */
  class ZORBA_DLL_PUBLIC StackFrame
  {
    public:

      virtual
      ~StackFrame() {}

      virtual const std::string&
      getSignature() const = 0;

      virtual const QueryLocation&
      getLocation() const = 0;
  };

  //string serialization of the query 
  ZORBA_DLL_PUBLIC
  std::ostream& operator<< (std::ostream& os, const QueryLocation& aQuery); 
  ZORBA_DLL_PUBLIC
  std::ostream& operator<< (std::ostream& os, const QueryLocation* aQuery); 

  /**
   * @brief A DBGP client implementation for commands.
   *
   * This is the client implementation for sending commands
   * according to the specification of DBGP. DBGP is used as
   * the default communication format in the Zorba debugger.
   */
  class ZORBA_DLL_PUBLIC DebuggerClient {
  public:
    /**
     * @brief creates a new instance of a DebuggerClient implementation.
     *
     * @param aHandler The event handler, where answered should get delivered to.
     * @param aPort The port the client should listen to.
     * @param aHost the host the client should listen to
     * @return A DebuggerClient implementation.
     */
    static DebuggerClient* createDebuggerClient(DebuggerEventHandler* aHandler,
                                                unsigned short aPort,
                                                const std::string& aHost);
  public:
	  virtual ~DebuggerClient() {};
  public: // Types
    typedef enum {
      Line,
      Call,
      Return,
      Exception,
      Conditional,
      Watch
    } BreakpointType;
    typedef enum {
      BiggerEqual,
      Equal,
      Multiple
    } HitCondition;
    typedef enum {
      Stdout,
      Stderr,
      Stdin
    } OutputStream;
    typedef enum {
      Disable,
      CopyData,
      Redirection
    } StreamBehaviour;
  public: // API
    /**
     * @brief Waits for a debug engine to attach.
     *
     * This method blocks until a debug engine attaches and sends the
     * init message. After that process, the appropriate method in the
     * DebugHandler gets called.
     */
    virtual void accept() = 0;
    
    /**
     * The status command is a simple way for the IDE to find out from
     * the debugger engine whether execution may be continued or not. no
     * body is required on request. If async support has been negotiated
     * using feature_get/set the status command may be sent while the
     * debugger engine is in a 'run state'.
     * 
     * The status attribute values of the response may be:
     * 
     * <ul>
     *   <li>
     *     starting:
     *      State prior to execution of any code
     *   </li>
     *   <li>
     *     stopping:
     *     State after completion of code execution.
     *     This typically happens at the end of code execution, allowing
     *     the IDE to further interact with the debugger engine (for example,
     *     to collect performance data, or use other extended commands).
     *   </li>
     *   <li>
     *     stopped:
     *     IDE is detached from process, no further interaction is possible.
     *   </li>
     *   <li>
     *     running:
     *     code is currently executing. Note that this state would only be
     *     seen with async support turned on, otherwise the typical state during
     *     IDE/debugger interaction would be 'break'
     *   </li>
     *   <li>
     *     break:
     *     code execution is paused, for whatever reason (see below), and the
     *     IDE/debugger can pass information back and forth.
     *   </li>
     * </ul>
     * The reason attribute value may be:
     * 
     * <ul>
     *   <li>
     *     ok
     *   </li>
     *   <li>
     *     error
     *   </li>
     *   <li>
     *     aborted
     *   </li>
     *   <li>
     *     exception
     *   </li>
     * </ul>
     *
     * @return The id of the request.
     */
    virtual std::size_t status() = 0;

    /**
     * @brief Get the variables in all the contexts in the topmost stack frame.
     *
     * @return The id of the request.
     */
    virtual std::size_t variables() = 0;
    
    /**
     * @brief Query the debug engine for supported features.
     *
     * @param aFeatureName The name of the feature to query for. values that must be
     *        supported by the debug engine are:
     *        <ul>
     *          <li>
     *            language_supports_threads
     *          </li>
     *          <li>
     *            language_name
     *          </li>
     *          <li>
     *            language_version
     *          </li>
     *          <li>
     *            encoding
     *          </li>
     *          <li>
     *            protocol_version
     *          </li>
     *          <li>
     *            supports_async
     *          </li>
     *          <li>
     *            data_encoding
     *          </li>
     *          <li>
     *            breakpoint_languages
     *          </li>
     *          <li>
     *            breakpoint_types
     *          </li>
     *        </ul>
     * @return The id of this request
     */
    virtual std::size_t feature_get(const std::string& aFeatureName) = 0;
    
    /**
     * @brief Set a specific feature of the engine.
     *
     * @param aFeatureName The name of the feature to query for. Values
     *        that must be supported by the debug engine are:
     *        <ul>
     *          <li>
     *            encoding
     *          </li>
     *          <li>
     *            multiple_sessions
     *          </li>
     *          <li>
     *            max_children
     *          </li>
     *          <li>
     *            max_children
     *          </li>
     *          <li>
     *            max_depth
     *          </li>
     *        </ul>
     * @param aValue The value of the feature
     * @return The id of this request
     */
    virtual std::size_t feature_set(const std::string& aFeatureName,
                                    const std::string& aValue) = 0;
    
    /**
     * @brief Send the run command to the debug engine.
     *
     * Sending this command to the debug engine makes the debug engine
     * to start if possible. Otherwise it must report an error.
     *
     * @return The id of this request
     */
    virtual std::size_t run() = 0;
    
    /**
     * @brief Send the step into command to the debug engine.
     *
     * @return The id of this request
     */
    virtual std::size_t step_into() = 0;
    
    /**
     * @brief Send the step out command to the debug engine.
     *
     * @return The id of this request
     */
    virtual std::size_t step_out() = 0;
    
    /**
     * @brief Send the step over command to the debug engine.
     *
     * @return The id of this request
     */
    virtual std::size_t step_over() = 0;
    
    /**
     * @brief Send the stop command to the debug engine.
     *
     * This command tells the debug engine, that it should
     * break the execution at the next point possible.
     *
     * @param withQuit This is a Zorba extension of the DBGP protocol that
     *    controls if the client should terminate execution and quit (true)
     *    or only terminate execution but not quit (false). This is used
     *    by command line clients that implement multiple query runs.
     * @return The id of this request
     */
    virtual std::size_t stop(bool withQuit) = 0;
    
    /**
     * @brief Send the detach command to the debug engine.
     *
     * @return The id of this request
     */
    virtual std::size_t detach() = 0;
    
    /**
     * @brief Send a command to the debug engine to set a new breakpoint.
     *
     * @param aType The type of the breakpoint (line, call, return etc.).
     * @param aEnabled Should the breakpoint be enabled?
     * @param aLinenumber The line number where to set the breakpoint.
     * @param aFilename The file where a breakpoint should be set.
     * @param aFunctionName The name of the function where to break (only
     *                      to be used if aType == Call || aType == Return)
     * @param aExceptionName The name of the exception to break (only to be used
     *                   if aType == Exception)
     * @param hit_value A numeric value used together with the hit_condition
     *                  to determine if the breakpoint should pause execution
     *                  or be skipped.
     * @param aCondition The condition used together with 'hit_value' (default
     *                   is '>=')
     * @param aIsTemporary Flag to define if breakpoint is temporary. A
     *                     temporary breakpoint is one that is deleted after
     *                     its first use. This is useful for features like "Run
     *                     to Cursor". Once the debugger engine uses a temporary
     *                     breakpoint, it should automatically remove the
     *                     breakpoint from it's list of valid breakpoints.
     * @param aExpression code expression, in the language of the debugger engine.
     *                    The breakpoint should activate when the evaluated code
     *                    evaluates to true. (required for conditional breakpoint
     *                    types)
     * @return The id of this request
     */
    virtual std::size_t breakpoint_set(BreakpointType aType,
                                       bool aEnabled = true,
                                       const std::string& aFilename = "",
                                       int aLinenumber = -1,
                                       const std::string& aFunctionName = "",
                                       const std::string& aExceptionName = "",
                                       unsigned hit_value = 0,
                                       HitCondition aCondition = BiggerEqual,
                                       bool aIsTemporary = false,
                                       const std::string& aExpression = "") = 0;
    
    /**
     * @brief Get information about a breakpoint.
     *
     * @param aBreakpointId The id of the breakpoint.
     * @return The id of this request
     */
    virtual std::size_t breakpoint_get(std::size_t aBreakpointId) = 0;
    
    /**
     * @brief Send a command to the debug engine to update a breakpoint.
     *
     * @param aBreakpointId The id of the breakpoint.
     * @param aEnabled Should the breakpoint be enabled?
     * @param aLinenumber The line number where to set the breakpoint.
     * @param hit_value A numeric value used together with the hit_condition
     *                  to determine if the breakpoint should pause execution
     *                  or be skipped.
     * @param aCondition The condition used together with 'hit_value' (default
     *                   is '>=')
     * @return The id of this request
     */
    virtual std::size_t breakpoint_update(std::size_t aBreakpointId,
                                          bool aEnabled = true,
                                          int aLinenumber = -1,
                                          unsigned hit_value = 0,
                                          HitCondition aCondition = BiggerEqual) = 0;
    
    /**
     * @brief Remove a breakpoint.
     *
     * @param aBreakpointId The id of the breakpoint.
     * @return The id of this request
     */
    virtual std::size_t breakpoint_remove(std::size_t aBreakpointId) = 0;
    
    /**
     * @brief Query all breakpoints.
     *
     * @return The id of this request
     */
    virtual std::size_t breakpoint_list() = 0;
    
    /**
     * @brief Get the depth of the stack.
     *
     * @return The id of this request
     */
    virtual std::size_t stack_depth() = 0;
    
    /**
     * @brief Get information about the stack at a given depth.
     *
     * @param depth The depth on which to quey (optional)
     * @return The id of this request
     */
    virtual std::size_t stack_get(int depth = -1) = 0;
    
    /**
     * @brief Get the context names at a given stack depth.
     *
     * The context names are the names in which variables are
     * (like global, local etc.).
     *
     * @param depth The depth on which to quey (optional)
     * @return The id of this request
     */
    virtual std::size_t context_names(int depth = -1) = 0;
    
    /**
     * @brief Get the context at a given stack depth.
     *
     * Returns an array of properties in a given context at a given
     * stack depth. If the stack depth is omitted, the current stack
     * depth is used. If the context name is omitted, the context
     * with an id zero is used (generally the 'locals' context).
     *
     * @param depth The depth on which to quey (optional)
     * @param contextId The contextId (optional)
     * @return The id of this request
     */
    virtual std::size_t context_get(int depth = -1, int contextId = -1) = 0;
    
    /**
     * @brief Get a mapping of types.
     *
     * The IDE calls this command to get information on how to map
     * language specific type names (as received in the property
     * element returned by the context_get, and property_* commands).
     * The debugger engine returns all data types that it supports. There
     * may be multiple map elements with the same type attribute value,
     * but the name value must be unique. This allows a language to map
     * multiple language specific types into one of the common data types
     * (eg. float and double can both be mapped to float).
     *
     * @return The id of this request
     */
    virtual std::size_t typemap_get() = 0;
    
    /**
     * @brief Get a property
     *
     * @param aPropertyLongName roperty long name (required)
     * @param aStackDepth stack depth (optional)
     * @param aContextId The context id for which to query.
     * @param aMaxDataSize The maximal size of the data sent back
     *                     from the debug engine.
     * @param aDatapage
     * @param aPropertyKey
     * @return The id of this request
     */
    virtual std::size_t property_get(const std::string& aPropertyLongName,
                                     int aStackDepth = -1,
                                     int aContextId = -1,
                                     std::size_t aMaxDataSize = 0,
                                     int aDatapage = -1,
                                     const std::string& aPropertyKey = "") = 0;
    
    /**
     * @brief Set a property
     *
     * @param aPropertyLongName roperty long name (required)
     * @param aStackDepth stack depth (optional)
     * @param aContextId The context id for which to query.
     * @param aMaxDataSize The maximal size of the data sent back
     *                     from the debug engine.
     * @param aPropertyAddress property address as retrieved in a
     *                         property element (optional).
     * @return The id of this request
     */
    virtual std::size_t property_set(const std::string& aPropertyLongName,
                                     int aStackDepth = -1,
                                     int aContextId = -1,
                                     std::size_t aMaxDataSize = 0,
                                     const std::string& aPropertyAddress = "") = 0;
    
    /**
     * @brief Get the value of a property
     *
     * @param aPropertyLongName roperty long name (required)
     * @param aStackDepth stack depth (optional)
     * @param aContextId The context id for which to query.
     * @param aMaxDataSize The maximal size of the data sent back
     *                     from the debug engine.
     * @param aDatapage
     * @param aPropertyKey property key as retrieved in a property
     *                     element (optional)
     * @param aPropertyAddress property address as retrieved in a
     *                         property element (optional).
     * @return The id of this request
     */
    virtual std::size_t property_value(const std::string& aPropertyLongName,
                                       int aStackDepth = -1,
                                       int aContextId = -1,
                                       std::size_t aMaxDataSize = 0,
                                       int aDatapage = -1,
                                       const std::string& aPropertyKey = "",
                                       const std::string& aPropertyAddress = "") = 0;
    
    /**
     * @brief List the source code at a given position.
     *
     * @param aFile The URI of the file the debug engine should deliver.
     * @param aBeginLine The starting point on which line the debug engine
     *        should start to read.
     * @param aEndLine The line number where the debug engine should stop
     *                 reading from the file.
     * @return The id of this request.
     */
    virtual std::size_t source(const std::string& aFile, unsigned aBeginLine = 0, unsigned aEndLine = 0) = 0;
    
    /**
     * @brief Setting a stream option.
     *
     * This method is used to tell the debug engine how to handle I/O. The debug
     * engine either reads and writes from/to stdin/stdout or it can also copy it
     * to the client or it can read/write everything from the client.
     *
     * @param aStream Specifies for which stream the option should be changed.
     * @param aBehaviour Specifies which behaviour the debug client should have
     *                   for reading/writing.
     * @return The id of this request
     */
    virtual std::size_t stream_option(OutputStream aStream, StreamBehaviour aBehaviour) = 0;
    
    /**
     * @brief Tell the debug engine to stop execution as fast as possible.
     *
     * @return The id of this request
     */
    virtual std::size_t do_break() = 0;
    
    /**
     * @brief Evaluates an expression.
     *
     * @param aExpr The expression to evaluate.
     * @return The id of this request
     */
    virtual std::size_t eval(const std::string& aExpr) = 0;
    
    /**
     * @brief Tells the client to quit. This method blocks until the client quit
     *        successfully.
     */
    virtual void quit() = 0;
  };

}//end of namespace

#endif
