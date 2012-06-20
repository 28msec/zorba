/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
package org.zorbaxquery.api.xqj;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import javax.xml.xquery.XQConstants;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItemType;
import org.zorbaxquery.api.*;
import org.zorbaxquery.api.ZorbaConstants.BoundarySpaceMode;
import org.zorbaxquery.api.ZorbaConstants.ConstructionMode;
import org.zorbaxquery.api.ZorbaConstants.InheritMode;
import org.zorbaxquery.api.ZorbaConstants.OrderEmptyMode;
import org.zorbaxquery.api.ZorbaConstants.OrderingMode;
import org.zorbaxquery.api.ZorbaConstants.PreserveMode;

  /** \brief 
   * 
   * An ZorbaXQStaticContext represents default values for various XQuery Static Context Components. Further it includes the static XQJ properties for an XQExpression or XQPreparedExpression object.
   * 
   * The following XQuery Static Context Components are supported through the ZorbaXQStaticContext interface:
   * 
   * - Statically known namespaces
   * - Default element/type namespace
   * - Default function namespace
   * - Context item static type
   * - Default collation
   * - Construction mode
   * - Ordering mode
   * - Default order for empty sequences
   * - Boundary-space policy
   * - Copy-namespaces mode
   * - Base URI
   * 
   * As described in the XQuery specification, each of these default values can be overridden or augmented in the query prolog.
   * In addition ZorbaXQStaticContext includes the static XQJ properties for an XQExpression or XQPreparedExpression object:
   * 
   * - Binding mode
   * - Holdability of the result sequences
   * - Scrollability of the result sequences
   * - Query language
   * - Query timeout
   *
   * Note that ZorbaXQStaticContext is a value object, changing attributes in such object doesn't affect any existing XQExpression or XQPreparedExpression object.
   * In order to take effect, the application needs to explicitly change the XQConnection default values, or specify an ZorbaXQStaticContext object when creating an XQExpression or XQPreparedExpression.
   * \code{.java}
   *   XQConnection conn = XQDatasource.getConnection();
   *   // get the default values from the implementation
   *   ZorbaXQStaticContext cntxt = conn.getStaticContext();
   *   // change the base uri
   *   cntxt.setBaseURI("http://www.foo.com/xml/");
   *   // change the implementation defaults
   *    conn.setStaticContext(cntxt);
   *  
   *   // create an XQExpression using the new defaults
   *   XQExpression expr1 = conn.createExpression();
   *  
   *   // creat an XQExpression, using BaseURI "file:///root/user/john/"
   *   cntxt.setBaseURI("file:///root/user/john/");
   *   XQExpression expr2 = conn.createExpression(cntxt);
   *   ... 
   * \endcode
   */
public class ZorbaXQStaticContext implements javax.xml.xquery.XQStaticContext {

    
    private StaticContext staticContext;
    private int scrollability = XQConstants.SCROLLTYPE_FORWARD_ONLY;
    private int holdability = XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT;
    private int queryLang = XQConstants.LANGTYPE_XQUERY;
    private int binding = XQConstants.BINDING_MODE_IMMEDIATE;
    Map<String, String> namespaces = new HashMap<String, String>();
    private StringVector uriPaths;
    private StringVector libPaths;
    private StringVector modulePaths;

    private Zorba zorba;
    private XQuery query;
    private ZorbaXQStaticCollectionManager lStaticCollectionManager;
    
    String baseURI = null;  //Patch for Zorba, bug filed on https://bugs.launchpad.net/zorba/+bug/905028
    XQItemType contextItemStaticType = null; //Patch for Zorba, TypeIdentifier is not complete
    protected StaticContext getZorbaStaticContext() {
      return staticContext;
    }
            
    public ZorbaXQStaticContext(Zorba aZorba) {
        zorba = aZorba;
        staticContext = zorba.createStaticContext();
        if (uriPaths!=null) {
            staticContext.setURIPath(uriPaths);
        }
    }
    public ZorbaXQStaticContext(XQuery aQuery) {
        query = aQuery;
        staticContext = query.getStaticContext();
        if (uriPaths!=null) {
            staticContext.setURIPath(uriPaths);
        }
    }

    protected void setURIPaths(StringVector aURIPath) {
        uriPaths = aURIPath;
        if (staticContext!=null) {
            staticContext.setURIPath(uriPaths);
        }
    }
    protected void setLIBPaths(StringVector aLIBPath) {
        libPaths = aLIBPath;
        if (staticContext!=null) {
            staticContext.setLIBPath(libPaths);
        }
    }
    protected void setMODPaths(StringVector aMODPath) {
        modulePaths = aMODPath;
        if (staticContext!=null) {
            staticContext.setModulePath(modulePaths);
        }
    }

  /** \brief Returns the prefixes of all the statically known namespaces. 
   * Use the getNamespaceURI method to look up the namespace URI corresponding to a specific prefix.
   * 
   * @return String array containing the namespace prefixes. Cannot be null
   */
    @Override
    public String[] getNamespacePrefixes() {
        
        StringPairVector bindings = staticContext.getNamespaceBindings();
        Collection<String> stringBindings = new ArrayList<String>();
        int size= (int) bindings.size();
        for (int i=0; i<size; i++) {
            StringPair pair = bindings.get(i);
            stringBindings.add(pair.getFirst());
        }
        return stringBindings.toArray(new String[0]);
    }

  /** \brief Retrieves the namespace URI associated with a prefix.
   * An XQException is thrown if an unknown prefix is specified, i.e. a prefix not returned by the getInScopeNamespacePrefixes method.
   * 
   * @param prefix - the prefix for which the namespace URI is sought. Cannot be null
   * @return the namespace URI. Cannot be null
   * @throw XQException - if a null prefix is specified or if the prefix is unknown
   */
    @Override
    public String getNamespaceURI(String prefix) throws XQException {
        isNullXQException(prefix);
        String result = null;
        try {
            result = staticContext.getNamespaceURIByPrefix(prefix);
        } catch (Exception e) {
            throw new XQException("Error getting Namespace URI" + e.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Declares a namespace prefix and associates it with a namespace URI.
   * If the namespace URI is the empty string, the prefix is removed from the in-scope namespace definitions.
   * 
   * @param prefix - the prefix for the namespace URI
   * @param URI - the namespace URI. An empty string undeclares the specific prefix. Cannot be null
   * @throw XQException - if (1) a null prefix, or (2) a null namespace URI is specified
   */
    @Override
    public void declareNamespace(String prefix, String URI) throws XQException {
        isNullXQException(prefix);
        isNullXQException(URI);
        try {
            if ((URI.isEmpty()) && (namespaces.containsKey(prefix))) {
                namespaces.remove(prefix);
                StaticContext sc = null;
                if (zorba==null) {
                    sc = query.getStaticContext();
                } else {
                    sc = zorba.createStaticContext();
                }
                StringPairVector scNamespaces = sc.getNamespaceBindings();
                int scNamespacesSize = (int) scNamespaces.size();
                
                for (String key: namespaces.keySet()) {
                    Boolean found = false;
                    for (int i = 0; i<scNamespacesSize; i++) {
                        StringPair pair = scNamespaces.get(i);
                        if (key.equalsIgnoreCase(pair.getFirst())) {
                            found = true;
                        }
                    }
                    if (!found) {
                        sc.addNamespace(key, namespaces.get(key));
                    }
                }
                staticContext = sc;
                 
            } else {
                staticContext.addNamespace(prefix, URI);
                namespaces.put(prefix, URI);
            }
        } catch (Exception e) {
            throw new XQException("Error declaring namespace on static context:" + e.getLocalizedMessage());
        }
    }

  /** \brief Gets the URI of the default element/type namespace, the empty string if not set.
   * 
   * @return the URI of the default element/type namespace, if set, else the empty string. Cannot be null
   */
    @Override
    public String getDefaultElementTypeNamespace() {
        return staticContext.getDefaultElementAndTypeNamespace();
    }

  /** \brief Sets the URI of the default element/type namespace, the empty string to make it unspecified.
   * 
   * @param URI - the namespace URI of the default element/type namespace, the empty string to make it unspecified. Cannot be null.
   * @throw XQException - if a null uri is specified
   */
    @Override
    public void setDefaultElementTypeNamespace(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultElementAndTypeNamespace(URI);
    }

  /** \brief Gets the URI of the default function namespace, the empty string if not set.
   * 
   * @return the URI of the default function namespace, if set, else the empty string. Cannot be null
   */
    @Override
    public String getDefaultFunctionNamespace() {
        return staticContext.getDefaultFunctionNamespace();
    }

  /** \brief Sets the URI of the default function namespace, the empty string to make it unspecified.
   * 
   * @param URI - the namespace URI of the default function namespace, the empty string to make it unspecified. Cannot be null.
   * @throw XQException - if a null URI is specified
   */
    @Override
    public void setDefaultFunctionNamespace(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultFunctionNamespace(URI);
    }

  /** \brief Gets the static type of the context item. null if unspecified.
   * 
   * @return the static type of the context item, if set, else null
   */
    @Override
    public XQItemType getContextItemStaticType() {
        //not very complete implementation
        //TypeIdentifier type = staticContext.getContextItemStaticType();
        return contextItemStaticType;
    }

  /** \brief Sets the static type of the context item, specify null to make it unspecified.
   * 
   * @param xqit - the static type of the context item; null if unspecified.
   * @throw XQException - if the contextItemType is not a valid ZorbaXQItemType
   */
    @Override
    public void setContextItemStaticType(XQItemType xqit) throws XQException {
        contextItemStaticType = xqit;
        if (xqit instanceof XQItemType) {
            org.zorbaxquery.api.xqj.ZorbaXQItemType wrapper = (org.zorbaxquery.api.xqj.ZorbaXQItemType) xqit;
            staticContext.setContextItemStaticType(wrapper.getTypeIdentifier());
        }
    }

  /** \brief Gets the URI of the default collation.
   * 
   * @return the URI of the default collation. Cannot be null.
   */
    @Override
    public String getDefaultCollation() {
        return staticContext.getDefaultCollation();
    }

  /** \brief Sets the URI of the default collation.
   * 
   * @param URI - the namespace URI of the default collation. Cannot be null.
   * @throw XQException - if a null URI is specified
   */
    @Override
    public void setDefaultCollation(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultCollation(URI);
    }

  /** \brief Gets the construction mode defined in the static context.
   * 
   * @return construction mode value. One of: XQConstants.CONSTRUCTION_MODE_PRESERVE, XQConstants.CONSTRUCTION_MODE_STRIP
   */
    @Override
    public int getConstructionMode() {
        int result = XQConstants.CONSTRUCTION_MODE_PRESERVE;
        int mode = staticContext.getConstructionMode();
        if (mode == ConstructionMode.STRIP_CONSTRUCTION) {
            result = XQConstants.CONSTRUCTION_MODE_STRIP;
        }
        return result;
    }

  /** \brief Sets the construction mode in the static context.
   * 
   * @param i - construction mode value. One of: XQConstants.CONSTRUCTION_MODE_PRESERVE, XQConstants.CONSTRUCTION_MODE_STRIP.
   * @throw XQException - the specified mode is different from XQConstants.CONSTRUCTION_MODE_PRESERVE, XQConstants.CONSTRUCTION_MODE_STRIP
   */
    @Override
    public void setConstructionMode(int i) throws XQException {
        if (!((i==XQConstants.CONSTRUCTION_MODE_PRESERVE) || (i==XQConstants.CONSTRUCTION_MODE_STRIP))) {
            throw new XQException("Invalid construction mode.");
        }
        int mode = ConstructionMode.STRIP_CONSTRUCTION;
        if (i==XQConstants.CONSTRUCTION_MODE_PRESERVE) {
            mode = ConstructionMode.PRESERVE_CONSTRUCTION;
        }
        staticContext.setConstructionMode(mode);
    }

  /** \brief Gets the ordering mode defined in the static context.
   * 
   * @return ordering mode value. One of: XQConstants.ORDERING_MODE_ORDERED, XQConstants.ORDERING_MODE_UNORDERED.
   */
    @Override
    public int getOrderingMode() {
        int result = XQConstants.ORDERING_MODE_ORDERED;
        int mode = staticContext.getOrderingMode();
        if (mode == OrderingMode.UNORDERED) {
            result = XQConstants.ORDERING_MODE_UNORDERED;
        }
        return result;
    }

  /** \brief Sets the ordering mode in the static context.
   * 
   * @param i - ordering mode value. One of: XQConstants.ORDERING_MODE_ORDERED, XQConstants.ORDERING_MODE_UNORDERED.
   * @throw XQException - the specified mode is different from XQConstants.ORDERING_MODE_ORDERED, XQConstants.ORDERING_MODE_UNORDERED
   */
    @Override
    public void setOrderingMode(int i) throws XQException {
        if (!((i==XQConstants.ORDERING_MODE_ORDERED) || (i==XQConstants.ORDERING_MODE_UNORDERED))) {
            throw new XQException("Invalid ordering mode.");
        }
        int mode = OrderingMode.ORDERED;
        if (i==XQConstants.ORDERING_MODE_UNORDERED) {
            mode = OrderingMode.UNORDERED;
        }
        staticContext.setOrderingMode(mode);
    }

  /** \brief Gets the default order for empty sequences defined in the static context.
   * 
   * @return default order for empty sequences value. One of: XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST, XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST.
   */
    @Override
    public int getDefaultOrderForEmptySequences() {
        int result = XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST;
        int order = staticContext.getDefaultOrderForEmptySequences();
        if (order == OrderEmptyMode.EMPTY_LEAST) {
            result = XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST;
        }
        return result;
    }

  /** \brief Sets the default order for empty sequences in the static context.
   * 
   * @param i - the default order for empty sequences. One of: XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST, XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST.
   * @throw XQException - the specified order for empty sequences is different from XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST, XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST
   */
    @Override
    public void setDefaultOrderForEmptySequences(int i) throws XQException {
        if  (!((i == XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST) || (i==XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST))) {
            throw new XQException("Invalid order specified.");
        }
        int result = OrderEmptyMode.EMPTY_GREATEST;
        if (i == XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST) {
            result = OrderEmptyMode.EMPTY_LEAST;
        }
        staticContext.setDefaultOrderForEmptySequences(result);
    }

  /** \brief Gets the boundary-space policy defined in the static context.
   * 
   * @return the boundary-space policy value. One of: XQConstants.BOUNDARY_SPACE_PRESERVE, XQConstants.BOUNDARY_SPACE_STRIP.
   */
    @Override
    public int getBoundarySpacePolicy() {
        int result = XQConstants.BOUNDARY_SPACE_PRESERVE;
        int boundary = staticContext.getBoundarySpacePolicy();
        if (boundary == BoundarySpaceMode.STRIP_SPACE) {
            result = XQConstants.BOUNDARY_SPACE_STRIP;
        }
        return result;
    }

  /** \brief Sets the boundary-space policy in the static context.
   * 
   * @param i - boundary space policy. One of: XQConstants.BOUNDARY_SPACE_PRESERVE, XQConstants.BOUNDARY_SPACE_STRIP.
   * @throw XQException - the specified mode is different from XQConstants.BOUNDARY_SPACE_PRESERVE, XQConstants.BOUNDARY_SPACE_STRIP
   */
    @Override
    public void setBoundarySpacePolicy(int i) throws XQException {
        if  (!((i == XQConstants.BOUNDARY_SPACE_PRESERVE) || (i==XQConstants.BOUNDARY_SPACE_STRIP))) {
            throw new XQException("Invalid boundary specified.");
        }
        int result = BoundarySpaceMode.PRESERVE_SPACE;
        if (i == XQConstants.BOUNDARY_SPACE_STRIP) {
            result = BoundarySpaceMode.STRIP_SPACE;
        }
        staticContext.setBoundarySpacePolicy(result);
    }

  /** \brief Gets the preserve part of the copy-namespaces mode defined in the static context.
   * 
   * @return construction mode value. One of: XQConstants.COPY_NAMESPACES_MODE_PRESERVE, XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE.
   */
    @Override
    public int getCopyNamespacesModePreserve() {
        int result = XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE;
        int preserve = staticContext.getCopyNamespacesModePreserve();
        if (preserve == PreserveMode.PRESERVE) {
            result = XQConstants.COPY_NAMESPACES_MODE_PRESERVE;
        }
        return result;
    }

  /** \brief Sets the preserve part of the copy-namespaces mode in the static context.
   * 
   * @param i - ordering mode value. One of: XQConstants.COPY_NAMESPACES_MODE_PRESERVE, XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE.
   * @throw XQException - the specified mode is different from XQConstants.COPY_NAMESPACES_MODE_PRESERVE, XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE
   */
    @Override
    public void setCopyNamespacesModePreserve(int i) throws XQException {
        if (!((i==XQConstants.COPY_NAMESPACES_MODE_PRESERVE) || (i==XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE))) {
          throw new XQException("The specified mode is invalid.");
        }
        int inherit = staticContext.getCopyNamespacesModeInherit();
        int preserve = PreserveMode.NO_PRESERVE;
        if (i==XQConstants.COPY_NAMESPACES_MODE_PRESERVE) {
            preserve = PreserveMode.PRESERVE;
        }
        staticContext.setCopyNamespacesMode(preserve, inherit);
    }

  /** \brief Gets the inherit part of the copy-namespaces mode defined in the static context.
   * 
   * @return construction mode value. One of: XQConstants.COPY_NAMESPACES_MODE_INHERIT, XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT.
   */
    @Override
    public int getCopyNamespacesModeInherit() {
        int result = XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT;
        int inherit = staticContext.getCopyNamespacesModeInherit();
        if (inherit == InheritMode.INHERIT) {
            result = XQConstants.COPY_NAMESPACES_MODE_INHERIT;
        }
        return result;
    }

  /** \brief Sets the inherit part of the copy-namespaces mode in the static context.
   * 
   * @param i - ordering mode value. One of: XQConstants.COPY_NAMESPACES_MODE_INHERIT, XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT.
   * @throw XQException - the specified mode is different from XQConstants.COPY_NAMESPACES_MODE_INHERIT, XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT
   */
    @Override
    public void setCopyNamespacesModeInherit(int i) throws XQException {
        if (!((i==XQConstants.COPY_NAMESPACES_MODE_INHERIT) || (i==XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT))) {
          throw new XQException("The specified mode is invalid.");
        }
        int preserve = staticContext.getCopyNamespacesModePreserve();
        int inherit = InheritMode.NO_INHERIT;
        if (i==XQConstants.COPY_NAMESPACES_MODE_INHERIT) {
            inherit = InheritMode.INHERIT;
        }
        staticContext.setCopyNamespacesMode(preserve, inherit);
    }

  /** \brief Gets the Base URI, if set in the static context, else the empty string.
   * 
   * @return the base URI, if set, else the empty string. Cannot be null..
   */
    @Override
    public String getBaseURI() {
        if (baseURI==null) {
            return staticContext.getBaseURI();
        } else {
            return baseURI;
        }
    }

  /** \brief Sets the Base URI in the static context, specify the empty string to make it undefined.
   * 
   * @param URI - the new baseUri, or empty string to make it undefined. Cannot be null.
   * @throw XQException - if a null base uri is specified
   */
    @Override
    public void setBaseURI(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setBaseURI(URI);
        baseURI = URI;
    }

  /** \brief Gets the value of the binding mode property.
   * By default an XQJ implementation operates in immediate binding mode.
   * 
   * @return the binding mode. One of XQConstants.BINDING_MODE_IMMEDIATE, orXQConstants.BINDING_MODE_DEFERRED.
   */
    @Override
    public int getBindingMode() {
        return binding;
    }

  /** \brief Sets the binding mode property.
   * By default an XQJ implementation operates in immediate binding mode.
   * 
   * @param i - the binding mode. One of: XQConstants.BINDING_MODE_IMMEDIATE, orXQConstants.BINDING_MODE_DEFERRED.
   * @throw XQException - the specified mode is different from XQConstants.BINDING_MODE_IMMEDIATE, XQConstants.BINDING_MODE_DEFERRED
   */
    @Override
    public void setBindingMode(int i) throws XQException {
        if (!((i==XQConstants.BINDING_MODE_DEFERRED) || (i==XQConstants.BINDING_MODE_IMMEDIATE))) {
          throw new XQException("The specified mode is invalid.");
        }
        binding = i;
    }

  /** \brief Gets the value of the holdability property.
   * 
   * @return the type of a result's holdability. One of: XQConstants.HOLDTYPE_HOLD_CURSORS_OVER_COMMIT, or XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT.
   */
    @Override
    public int getHoldability() {
        return holdability;
    }

  /** \brief Sets the holdability property.
   * 
   * @param i - the holdability of the result. One of: XQConstants.HOLDTYPE_HOLD_CURSORS_OVER_COMMIT, or XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT.
   * @throw XQException - the specified holdability is different from XQConstants.HOLDTYPE_HOLD_CURSORS_OVER_COMMIT, XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT
   */
    @Override
    public void setHoldability(int i) throws XQException {
        if (!((i==XQConstants.HOLDTYPE_HOLD_CURSORS_OVER_COMMIT) || (i==XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT))) {
            throw new XQException ("Invalid holdability parameter.");
        }
        holdability = i;
    }

  /** \brief Gets the value of the language type and version property.
   * By default an XQJ implementation's default is XQConstants.LANGTYPE_XQUERY.
   * 
   * @return the language type and version. One of: XQConstants.LANGTYPE_XQUERY, or XQConstants.LANGTYPE_XQUERYX or a negative value indicating a vendor specific query language type and version.
   */
    @Override
    public int getQueryLanguageTypeAndVersion() {
        return queryLang;
    }

  /** \brief Sets the input query language type and version.
   * When this is set to a particular language type and version, then the query is assumed to be in that language and version.
   * 
   * @param i - the query language type and version of the inputs. One of: XQConstants.LANGTYPE_XQUERY (default), or XQConstants.LANGTYPE_XQUERYX. A negative number indicates a vendor specific query language type and version.
   * @throw XQException - the specified langtype is different from XQConstants.LANGTYPE_XQUERY, XQConstants.LANGTYPE_XQUERYX and is not negative
   */
    @Override
    public void setQueryLanguageTypeAndVersion(int i) throws XQException {
        if (!((i==XQConstants.LANGTYPE_XQUERY) || (i==XQConstants.LANGTYPE_XQUERYX))) {
            throw new XQException ("Invalid holdability parameter.");
        }
        queryLang = i;
    }

  /** \brief Gets the value of the scrollability property.
   * By default query results are forward only.
   * 
   * @return the type of a result's scrollability. One of: XQConstants.SCROLLTYPE_FORWARD_ONLY, or XQConstants.SCROLLTYPE_SCROLLABLE.
   */
    @Override
    public int getScrollability() {
        return scrollability;
    }

  /** \brief Sets the scrollability of the result sequence.
   * By default query results are forward only.
   * 
   * @param i - the scrollability of the result. One of: XQConstants.SCROLLTYPE_FORWARD_ONLY, or XQConstants.SCROLLTYPE_SCROLLABLE.
   * @throw XQException - the specified crollability type is different from XQConstants.SCROLLTYPE_FORWARD_ONLY, XQConstants.SCROLLTYPE_SCROLLABLE
   */
    @Override
    public void setScrollability(int i) throws XQException {
        if (!((i==XQConstants.SCROLLTYPE_FORWARD_ONLY) || (i==XQConstants.SCROLLTYPE_SCROLLABLE))) {
            throw new XQException ("Invalid scroll type.");
        }
        scrollability = i;
    }

  /** \brief Retrieves the number of seconds an implementation will wait for a query to execute.
   * 
   * @return the query execution timeout value in seconds. A value of 0 indicates no limit.
   */
    @Override
    public int getQueryTimeout() {
        return 0;
    }

  /** \brief Sets the number of seconds an implementation will wait for a query to execute.
   * If the implementation does not support query timeout it can ignore the specified timeout value. It the limit is exceeded, the behavor of the query is the same as an execution of a cancel by another thread.
   * 
   * @param i - the query execution timeout value in seconds. A value of 0 indicates no limit
   * @throw XQException - if the passed in value is negative
   */
    @Override
    public void setQueryTimeout(int i) throws XQException {
        if (i<0) {
            throw new XQException("Value can't be negative.");
        }
    }

  /** \brief Returns a StaticCollectionManager.
   * 
   * Returns a CollectionManager responsible for all collections which are statically declared in the static context of this query (main module) or any transitively imported library module.
   * The collection manager provides a set of functions for managing collections and their contents.
   *
   * @return ZorbaXQStaticCollectionManager The collection manager responsible for managing collections of this Sequence.
   * @throw XQException - if the object is closed
   */
    public ZorbaXQStaticCollectionManager getStaticCollectionManager() throws XQException {
        if (lStaticCollectionManager==null) {
            lStaticCollectionManager = new ZorbaXQStaticCollectionManager(staticContext.getStaticCollectionManager());
        }
        return lStaticCollectionManager;
    }

    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
    
}
