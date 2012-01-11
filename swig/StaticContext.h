#include <zorba/static_context_consts.h>

class StaticContext 
{
friend class Zorba;
friend class XQuery;

private:
  zorba::StaticContext_t theStaticContext;
public:
  StaticContext();
  StaticContext(const StaticContext& aStaticContext);
  StaticContext(zorba::StaticContext_t aStaticContext);
  
  virtual void addColation(const std::string& aURI); 
  virtual bool addNamespace(const std::string& aPrefix,
                            const std::string& aURI);
  void addReference() const;
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const;

  virtual StaticContext createChildContext() const;
  virtual void declareOption(const Item &aQName, 
                             const std::string &aOptionVal);
  virtual void disableFunction(const Item &aQName, int arity);

  virtual void free ();
  virtual std::string getBaseURI () const;
  virtual zorba::boundary_space_mode_t getBoundarySpacePolicy () const;

  virtual zorba::construction_mode_t getConstructionMode () const;
  virtual void getCopyNamespacesMode (zorba::preserve_mode_t &aPreserve, zorba::inherit_mode_t &aInherit) const;
  virtual std::string getDefaultCollation () const;
  virtual std::string getDefaultElementAndTypeNamespace () const;
  virtual std::string getDefaultFunctionNamespace () const;
  virtual zorba::order_empty_mode_t getDefaultOrderForEmptySequences () const;

  virtual std::string getNamespaceURIByPrefix(const std::string &aPrefix) const;
  virtual bool getOption(const Item &aQName, std::string &aOptionValue) const;
  virtual zorba::ordering_mode_t getOrderingMode() const;
  long getRefCount() const;
  virtual zorba::validation_mode_t getRevalidationMode();
  virtual zorba::xpath1_0compatib_mode_t getXPath1_0CompatibMode () const;
  virtual void loadProlog (const std::string & aProlog, 
                           const CompilerHints &hints);

  void removeReference ();
  virtual void resetTraceStream ();
  virtual bool setBaseURI (const std::string &aBaseURI);
  virtual bool setBoundarySpacePolicy (zorba::boundary_space_mode_t aMode);

  virtual bool setConstructionMode (zorba::construction_mode_t aMode);

  virtual bool setCopyNamespacesMode (zorba::preserve_mode_t aPreserve, 
                                      zorba::inherit_mode_t aInherit);
  virtual void setDefaultCollation (const std::string &aURI);
  virtual bool setDefaultElementAndTypeNamespace (const std::string &aURI);
  virtual bool setDefaultFunctionNamespace (const std::string &aURI);
  virtual bool setDefaultOrderForEmptySequences (zorba::order_empty_mode_t aMode);

  virtual bool setOrderingMode (zorba::ordering_mode_t aMode);
  virtual void setRevalidationMode (zorba::validation_mode_t aMode);

  virtual bool setXPath1_0CompatibMode (zorba::xpath1_0compatib_mode_t aMode);

  void destroy();
}; // class StaticContext

