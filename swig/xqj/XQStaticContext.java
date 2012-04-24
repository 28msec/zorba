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
import org.zorbaxquery.api.StaticContext;
import org.zorbaxquery.api.StringPair;
import org.zorbaxquery.api.StringPairVector;
import org.zorbaxquery.api.StringVector;
import org.zorbaxquery.api.XQuery;
import org.zorbaxquery.api.Zorba;
import org.zorbaxquery.api.ZorbaConstants.BoundarySpaceMode;
import org.zorbaxquery.api.ZorbaConstants.ConstructionMode;
import org.zorbaxquery.api.ZorbaConstants.InheritMode;
import org.zorbaxquery.api.ZorbaConstants.OrderEmptyMode;
import org.zorbaxquery.api.ZorbaConstants.OrderingMode;
import org.zorbaxquery.api.ZorbaConstants.PreserveMode;

public class XQStaticContext implements javax.xml.xquery.XQStaticContext {

    
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
    
    String baseURI = null;  //Patch for Zorba, bug filed on https://bugs.launchpad.net/zorba/+bug/905028
    XQItemType contextItemStaticType = null; //Patch for Zorba, TypeIdentifier is not complete
    protected StaticContext getZorbaStaticContext() {
      return staticContext;
    }
            
    public XQStaticContext(Zorba aZorba) {
        zorba = aZorba;
        staticContext = zorba.createStaticContext();
        if (uriPaths!=null) {
            staticContext.setURIPath(uriPaths);
        }
    }
    public XQStaticContext(XQuery aQuery) {
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

    @Override
    public String getDefaultElementTypeNamespace() {
        return staticContext.getDefaultElementAndTypeNamespace();
    }

    @Override
    public void setDefaultElementTypeNamespace(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultElementAndTypeNamespace(URI);
    }

    @Override
    public String getDefaultFunctionNamespace() {
        return staticContext.getDefaultFunctionNamespace();
    }

    @Override
    public void setDefaultFunctionNamespace(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultFunctionNamespace(URI);
    }

    @Override
    public XQItemType getContextItemStaticType() {
        //not very complete implementation
        //TypeIdentifier type = staticContext.getContextItemStaticType();
        return contextItemStaticType;
    }

    @Override
    public void setContextItemStaticType(XQItemType xqit) throws XQException {
        contextItemStaticType = xqit;
        if (xqit instanceof XQItemType) {
            org.zorbaxquery.api.xqj.XQItemType wrapper = (org.zorbaxquery.api.xqj.XQItemType) xqit;
            staticContext.setContextItemStaticType(wrapper.getTypeIdentifier());
        }
    }

    @Override
    public String getDefaultCollation() {
        return staticContext.getDefaultCollation();
    }

    @Override
    public void setDefaultCollation(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setDefaultCollation(URI);
    }

    @Override
    public int getConstructionMode() {
        int result = XQConstants.CONSTRUCTION_MODE_PRESERVE;
        int mode = staticContext.getConstructionMode();
        if (mode == ConstructionMode.STRIP_CONSTRUCTION) {
            result = XQConstants.CONSTRUCTION_MODE_STRIP;
        }
        return result;
    }

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

    @Override
    public int getOrderingMode() {
        int result = XQConstants.ORDERING_MODE_ORDERED;
        int mode = staticContext.getOrderingMode();
        if (mode == OrderingMode.UNORDERED) {
            result = XQConstants.ORDERING_MODE_UNORDERED;
        }
        return result;
    }

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

    @Override
    public int getDefaultOrderForEmptySequences() {
        int result = XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_GREATEST;
        int order = staticContext.getDefaultOrderForEmptySequences();
        if (order == OrderEmptyMode.EMPTY_LEAST) {
            result = XQConstants.DEFAULT_ORDER_FOR_EMPTY_SEQUENCES_LEAST;
        }
        return result;
    }

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

    @Override
    public int getBoundarySpacePolicy() {
        int result = XQConstants.BOUNDARY_SPACE_PRESERVE;
        int boundary = staticContext.getBoundarySpacePolicy();
        if (boundary == BoundarySpaceMode.STRIP_SPACE) {
            result = XQConstants.BOUNDARY_SPACE_STRIP;
        }
        return result;
    }

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

    @Override
    public int getCopyNamespacesModePreserve() {
        int result = XQConstants.COPY_NAMESPACES_MODE_NO_PRESERVE;
        int preserve = staticContext.getCopyNamespacesModePreserve();
        if (preserve == PreserveMode.PRESERVE) {
            result = XQConstants.COPY_NAMESPACES_MODE_PRESERVE;
        }
        return result;
    }

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

    @Override
    public int getCopyNamespacesModeInherit() {
        int result = XQConstants.COPY_NAMESPACES_MODE_NO_INHERIT;
        int inherit = staticContext.getCopyNamespacesModeInherit();
        if (inherit == InheritMode.INHERIT) {
            result = XQConstants.COPY_NAMESPACES_MODE_INHERIT;
        }
        return result;
    }

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

    @Override
    public String getBaseURI() {
        if (baseURI==null) {
            return staticContext.getBaseURI();
        } else {
            return baseURI;
        }
    }

    @Override
    public void setBaseURI(String URI) throws XQException {
        isNullXQException(URI);
        staticContext.setBaseURI(URI);
        baseURI = URI;
    }

    @Override
    public int getBindingMode() {
        return binding;
    }

    @Override
    public void setBindingMode(int i) throws XQException {
        if (!((i==XQConstants.BINDING_MODE_DEFERRED) || (i==XQConstants.BINDING_MODE_IMMEDIATE))) {
          throw new XQException("The specified mode is invalid.");
        }
        binding = i;
    }

    @Override
    public int getHoldability() {
        return holdability;
    }

    @Override
    public void setHoldability(int i) throws XQException {
        if (!((i==XQConstants.HOLDTYPE_HOLD_CURSORS_OVER_COMMIT) || (i==XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT))) {
            throw new XQException ("Invalid holdability parameter.");
        }
        holdability = i;
    }

    @Override
    public int getQueryLanguageTypeAndVersion() {
        return queryLang;
    }

    @Override
    public void setQueryLanguageTypeAndVersion(int i) throws XQException {
        if (!((i==XQConstants.LANGTYPE_XQUERY) || (i==XQConstants.LANGTYPE_XQUERYX))) {
            throw new XQException ("Invalid holdability parameter.");
        }
        queryLang = i;
    }

    @Override
    public int getScrollability() {
        return scrollability;
    }

    @Override
    public void setScrollability(int i) throws XQException {
        if (!((i==XQConstants.SCROLLTYPE_FORWARD_ONLY) || (i==XQConstants.SCROLLTYPE_SCROLLABLE))) {
            throw new XQException ("Invalid scroll type.");
        }
        scrollability = i;
    }

    @Override
    public int getQueryTimeout() {
        return 0;
    }

    @Override
    public void setQueryTimeout(int i) throws XQException {
        if (i<0) {
            throw new XQException("Value can't be negative.");
        }
    }

    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
    
}
