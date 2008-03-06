

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Thu Mar 06 15:09:49 2008
 */
/* Compiler settings for .\ZorbaCOMApi.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ZorbaCOMApi_h__
#define __ZorbaCOMApi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IZorbaBaseEngine_FWD_DEFINED__
#define __IZorbaBaseEngine_FWD_DEFINED__
typedef interface IZorbaBaseEngine IZorbaBaseEngine;
#endif 	/* __IZorbaBaseEngine_FWD_DEFINED__ */


#ifndef __IZorbaSingleThread_FWD_DEFINED__
#define __IZorbaSingleThread_FWD_DEFINED__
typedef interface IZorbaSingleThread IZorbaSingleThread;
#endif 	/* __IZorbaSingleThread_FWD_DEFINED__ */


#ifndef __IStaticQueryContext_FWD_DEFINED__
#define __IStaticQueryContext_FWD_DEFINED__
typedef interface IStaticQueryContext IStaticQueryContext;
#endif 	/* __IStaticQueryContext_FWD_DEFINED__ */


#ifndef __IXQueryTreePlans_FWD_DEFINED__
#define __IXQueryTreePlans_FWD_DEFINED__
typedef interface IXQueryTreePlans IXQueryTreePlans;
#endif 	/* __IXQueryTreePlans_FWD_DEFINED__ */


#ifndef __IXQuery_FWD_DEFINED__
#define __IXQuery_FWD_DEFINED__
typedef interface IXQuery IXQuery;
#endif 	/* __IXQuery_FWD_DEFINED__ */


#ifndef __IDynamicQueryContext_FWD_DEFINED__
#define __IDynamicQueryContext_FWD_DEFINED__
typedef interface IDynamicQueryContext IDynamicQueryContext;
#endif 	/* __IDynamicQueryContext_FWD_DEFINED__ */


#ifndef __ZorbaSingleThread_FWD_DEFINED__
#define __ZorbaSingleThread_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZorbaSingleThread ZorbaSingleThread;
#else
typedef struct ZorbaSingleThread ZorbaSingleThread;
#endif /* __cplusplus */

#endif 	/* __ZorbaSingleThread_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_ZorbaCOMApi_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_ZorbaCOMApi_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZorbaCOMApi_0000_v0_0_s_ifspec;

#ifndef __IZorbaBaseEngine_INTERFACE_DEFINED__
#define __IZorbaBaseEngine_INTERFACE_DEFINED__

/* interface IZorbaBaseEngine */
/* [object][unique][helpstring][dual][uuid] */ 


EXTERN_C const IID IID_IZorbaBaseEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B633B682-F020-4486-A8BE-ED827450485B")
    IZorbaBaseEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createQuery( 
            /* [in] */ BSTR aQueryString,
            /* [in] */ IStaticQueryContext *sctx,
            /* [in] */ BSTR xquery_source_uri,
            /* [in] */ VARIANT_BOOL routing_mode,
            /* [in] */ IXQueryTreePlans *tree_plans,
            /* [retval][out] */ IXQuery **xquery) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createDynamicQueryContext( 
            /* [retval][out] */ IDynamicQueryContext **dctx) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZorbaBaseEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZorbaBaseEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZorbaBaseEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZorbaBaseEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZorbaBaseEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZorbaBaseEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZorbaBaseEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZorbaBaseEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createQuery )( 
            IZorbaBaseEngine * This,
            /* [in] */ BSTR aQueryString,
            /* [in] */ IStaticQueryContext *sctx,
            /* [in] */ BSTR xquery_source_uri,
            /* [in] */ VARIANT_BOOL routing_mode,
            /* [in] */ IXQueryTreePlans *tree_plans,
            /* [retval][out] */ IXQuery **xquery);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createDynamicQueryContext )( 
            IZorbaBaseEngine * This,
            /* [retval][out] */ IDynamicQueryContext **dctx);
        
        END_INTERFACE
    } IZorbaBaseEngineVtbl;

    interface IZorbaBaseEngine
    {
        CONST_VTBL struct IZorbaBaseEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZorbaBaseEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZorbaBaseEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZorbaBaseEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZorbaBaseEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZorbaBaseEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZorbaBaseEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZorbaBaseEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZorbaBaseEngine_createQuery(This,aQueryString,sctx,xquery_source_uri,routing_mode,tree_plans,xquery)	\
    (This)->lpVtbl -> createQuery(This,aQueryString,sctx,xquery_source_uri,routing_mode,tree_plans,xquery)

#define IZorbaBaseEngine_createDynamicQueryContext(This,dctx)	\
    (This)->lpVtbl -> createDynamicQueryContext(This,dctx)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZorbaBaseEngine_createQuery_Proxy( 
    IZorbaBaseEngine * This,
    /* [in] */ BSTR aQueryString,
    /* [in] */ IStaticQueryContext *sctx,
    /* [in] */ BSTR xquery_source_uri,
    /* [in] */ VARIANT_BOOL routing_mode,
    /* [in] */ IXQueryTreePlans *tree_plans,
    /* [retval][out] */ IXQuery **xquery);


void __RPC_STUB IZorbaBaseEngine_createQuery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZorbaBaseEngine_createDynamicQueryContext_Proxy( 
    IZorbaBaseEngine * This,
    /* [retval][out] */ IDynamicQueryContext **dctx);


void __RPC_STUB IZorbaBaseEngine_createDynamicQueryContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZorbaBaseEngine_INTERFACE_DEFINED__ */


#ifndef __IZorbaSingleThread_INTERFACE_DEFINED__
#define __IZorbaSingleThread_INTERFACE_DEFINED__

/* interface IZorbaSingleThread */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZorbaSingleThread;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("200D051F-428D-4E59-9B69-FCB31BB4D517")
    IZorbaSingleThread : public IZorbaBaseEngine
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IZorbaSingleThreadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZorbaSingleThread * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZorbaSingleThread * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZorbaSingleThread * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZorbaSingleThread * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZorbaSingleThread * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZorbaSingleThread * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZorbaSingleThread * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createQuery )( 
            IZorbaSingleThread * This,
            /* [in] */ BSTR aQueryString,
            /* [in] */ IStaticQueryContext *sctx,
            /* [in] */ BSTR xquery_source_uri,
            /* [in] */ VARIANT_BOOL routing_mode,
            /* [in] */ IXQueryTreePlans *tree_plans,
            /* [retval][out] */ IXQuery **xquery);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createDynamicQueryContext )( 
            IZorbaSingleThread * This,
            /* [retval][out] */ IDynamicQueryContext **dctx);
        
        END_INTERFACE
    } IZorbaSingleThreadVtbl;

    interface IZorbaSingleThread
    {
        CONST_VTBL struct IZorbaSingleThreadVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZorbaSingleThread_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZorbaSingleThread_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZorbaSingleThread_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZorbaSingleThread_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZorbaSingleThread_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZorbaSingleThread_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZorbaSingleThread_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZorbaSingleThread_createQuery(This,aQueryString,sctx,xquery_source_uri,routing_mode,tree_plans,xquery)	\
    (This)->lpVtbl -> createQuery(This,aQueryString,sctx,xquery_source_uri,routing_mode,tree_plans,xquery)

#define IZorbaSingleThread_createDynamicQueryContext(This,dctx)	\
    (This)->lpVtbl -> createDynamicQueryContext(This,dctx)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZorbaSingleThread_INTERFACE_DEFINED__ */


#ifndef __IStaticQueryContext_INTERFACE_DEFINED__
#define __IStaticQueryContext_INTERFACE_DEFINED__

/* interface IStaticQueryContext */
/* [object][unique][helpstring][nonextensible][dual][uuid] */ 


EXTERN_C const IID IID_IStaticQueryContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D0BAB563-EBB6-4AD4-9B49-4C68A120E0BC")
    IStaticQueryContext : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalStaticQueryContextPtr( 
            /* [retval][out] */ VARIANT *internal_ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStaticQueryContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStaticQueryContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStaticQueryContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStaticQueryContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStaticQueryContext * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStaticQueryContext * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStaticQueryContext * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStaticQueryContext * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getInternalStaticQueryContextPtr )( 
            IStaticQueryContext * This,
            /* [retval][out] */ VARIANT *internal_ptr);
        
        END_INTERFACE
    } IStaticQueryContextVtbl;

    interface IStaticQueryContext
    {
        CONST_VTBL struct IStaticQueryContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStaticQueryContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStaticQueryContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStaticQueryContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStaticQueryContext_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStaticQueryContext_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStaticQueryContext_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStaticQueryContext_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStaticQueryContext_getInternalStaticQueryContextPtr(This,internal_ptr)	\
    (This)->lpVtbl -> getInternalStaticQueryContextPtr(This,internal_ptr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStaticQueryContext_getInternalStaticQueryContextPtr_Proxy( 
    IStaticQueryContext * This,
    /* [retval][out] */ VARIANT *internal_ptr);


void __RPC_STUB IStaticQueryContext_getInternalStaticQueryContextPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStaticQueryContext_INTERFACE_DEFINED__ */


#ifndef __IXQueryTreePlans_INTERFACE_DEFINED__
#define __IXQueryTreePlans_INTERFACE_DEFINED__

/* interface IXQueryTreePlans */
/* [object][unique][helpstring][nonextensible][dual][uuid] */ 


EXTERN_C const IID IID_IXQueryTreePlans;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F90F747-2AB3-43e6-BBFA-D22AA3EE65C0")
    IXQueryTreePlans : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalXQueryTreePlansPtr( 
            /* [retval][out] */ VARIANT *internal_ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXQueryTreePlansVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXQueryTreePlans * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXQueryTreePlans * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXQueryTreePlans * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXQueryTreePlans * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXQueryTreePlans * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXQueryTreePlans * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXQueryTreePlans * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getInternalXQueryTreePlansPtr )( 
            IXQueryTreePlans * This,
            /* [retval][out] */ VARIANT *internal_ptr);
        
        END_INTERFACE
    } IXQueryTreePlansVtbl;

    interface IXQueryTreePlans
    {
        CONST_VTBL struct IXQueryTreePlansVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXQueryTreePlans_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXQueryTreePlans_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXQueryTreePlans_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXQueryTreePlans_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXQueryTreePlans_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXQueryTreePlans_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXQueryTreePlans_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXQueryTreePlans_getInternalXQueryTreePlansPtr(This,internal_ptr)	\
    (This)->lpVtbl -> getInternalXQueryTreePlansPtr(This,internal_ptr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXQueryTreePlans_getInternalXQueryTreePlansPtr_Proxy( 
    IXQueryTreePlans * This,
    /* [retval][out] */ VARIANT *internal_ptr);


void __RPC_STUB IXQueryTreePlans_getInternalXQueryTreePlansPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXQueryTreePlans_INTERFACE_DEFINED__ */


#ifndef __IXQuery_INTERFACE_DEFINED__
#define __IXQuery_INTERFACE_DEFINED__

/* interface IXQuery */
/* [object][unique][helpstring][nonextensible][dual][uuid] */ 


EXTERN_C const IID IID_IXQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84757724-30DE-4190-8615-45FB3064039D")
    IXQuery : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalXQueryPtr( 
            /* [retval][out] */ VARIANT *internal_ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE initExecution( 
            /* [in] */ IDynamicQueryContext *dctx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE serializeXMLtoBuffer( 
            /* [retval][out] */ BSTR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXQueryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXQuery * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXQuery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXQuery * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXQuery * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXQuery * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXQuery * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXQuery * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getInternalXQueryPtr )( 
            IXQuery * This,
            /* [retval][out] */ VARIANT *internal_ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *initExecution )( 
            IXQuery * This,
            /* [in] */ IDynamicQueryContext *dctx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *serializeXMLtoBuffer )( 
            IXQuery * This,
            /* [retval][out] */ BSTR *result);
        
        END_INTERFACE
    } IXQueryVtbl;

    interface IXQuery
    {
        CONST_VTBL struct IXQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXQuery_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXQuery_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXQuery_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXQuery_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXQuery_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXQuery_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXQuery_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXQuery_getInternalXQueryPtr(This,internal_ptr)	\
    (This)->lpVtbl -> getInternalXQueryPtr(This,internal_ptr)

#define IXQuery_initExecution(This,dctx)	\
    (This)->lpVtbl -> initExecution(This,dctx)

#define IXQuery_serializeXMLtoBuffer(This,result)	\
    (This)->lpVtbl -> serializeXMLtoBuffer(This,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXQuery_getInternalXQueryPtr_Proxy( 
    IXQuery * This,
    /* [retval][out] */ VARIANT *internal_ptr);


void __RPC_STUB IXQuery_getInternalXQueryPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXQuery_initExecution_Proxy( 
    IXQuery * This,
    /* [in] */ IDynamicQueryContext *dctx);


void __RPC_STUB IXQuery_initExecution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXQuery_serializeXMLtoBuffer_Proxy( 
    IXQuery * This,
    /* [retval][out] */ BSTR *result);


void __RPC_STUB IXQuery_serializeXMLtoBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXQuery_INTERFACE_DEFINED__ */


#ifndef __IDynamicQueryContext_INTERFACE_DEFINED__
#define __IDynamicQueryContext_INTERFACE_DEFINED__

/* interface IDynamicQueryContext */
/* [object][unique][helpstring][nonextensible][dual][uuid] */ 


EXTERN_C const IID IID_IDynamicQueryContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB6B602E-8823-453A-90A1-005020B51434")
    IDynamicQueryContext : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalDynamicQueryContextPtr( 
            /* [retval][out] */ VARIANT *internal_ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setVariableAsInt( 
            /* [in] */ BSTR varname,
            /* [in] */ int int_value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setVariableAsString( 
            /* [in] */ BSTR varname,
            /* [in] */ BSTR str_value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setVariableAsDocumentFromFile( 
            /* [in] */ BSTR varname,
            /* [in] */ BSTR file_path,
            /* [in] */ BSTR storeUri) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteVariable( 
            /* [in] */ BSTR varname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteAllVariables( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setContextItemAsDocumentFromFile( 
            /* [in] */ BSTR file_path,
            /* [in] */ BSTR storeUri) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicQueryContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicQueryContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicQueryContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicQueryContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDynamicQueryContext * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDynamicQueryContext * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDynamicQueryContext * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDynamicQueryContext * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getInternalDynamicQueryContextPtr )( 
            IDynamicQueryContext * This,
            /* [retval][out] */ VARIANT *internal_ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setVariableAsInt )( 
            IDynamicQueryContext * This,
            /* [in] */ BSTR varname,
            /* [in] */ int int_value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setVariableAsString )( 
            IDynamicQueryContext * This,
            /* [in] */ BSTR varname,
            /* [in] */ BSTR str_value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setVariableAsDocumentFromFile )( 
            IDynamicQueryContext * This,
            /* [in] */ BSTR varname,
            /* [in] */ BSTR file_path,
            /* [in] */ BSTR storeUri);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deleteVariable )( 
            IDynamicQueryContext * This,
            /* [in] */ BSTR varname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deleteAllVariables )( 
            IDynamicQueryContext * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setContextItemAsDocumentFromFile )( 
            IDynamicQueryContext * This,
            /* [in] */ BSTR file_path,
            /* [in] */ BSTR storeUri);
        
        END_INTERFACE
    } IDynamicQueryContextVtbl;

    interface IDynamicQueryContext
    {
        CONST_VTBL struct IDynamicQueryContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicQueryContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDynamicQueryContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDynamicQueryContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDynamicQueryContext_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDynamicQueryContext_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDynamicQueryContext_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDynamicQueryContext_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDynamicQueryContext_getInternalDynamicQueryContextPtr(This,internal_ptr)	\
    (This)->lpVtbl -> getInternalDynamicQueryContextPtr(This,internal_ptr)

#define IDynamicQueryContext_setVariableAsInt(This,varname,int_value)	\
    (This)->lpVtbl -> setVariableAsInt(This,varname,int_value)

#define IDynamicQueryContext_setVariableAsString(This,varname,str_value)	\
    (This)->lpVtbl -> setVariableAsString(This,varname,str_value)

#define IDynamicQueryContext_setVariableAsDocumentFromFile(This,varname,file_path,storeUri)	\
    (This)->lpVtbl -> setVariableAsDocumentFromFile(This,varname,file_path,storeUri)

#define IDynamicQueryContext_deleteVariable(This,varname)	\
    (This)->lpVtbl -> deleteVariable(This,varname)

#define IDynamicQueryContext_deleteAllVariables(This)	\
    (This)->lpVtbl -> deleteAllVariables(This)

#define IDynamicQueryContext_setContextItemAsDocumentFromFile(This,file_path,storeUri)	\
    (This)->lpVtbl -> setContextItemAsDocumentFromFile(This,file_path,storeUri)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_getInternalDynamicQueryContextPtr_Proxy( 
    IDynamicQueryContext * This,
    /* [retval][out] */ VARIANT *internal_ptr);


void __RPC_STUB IDynamicQueryContext_getInternalDynamicQueryContextPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_setVariableAsInt_Proxy( 
    IDynamicQueryContext * This,
    /* [in] */ BSTR varname,
    /* [in] */ int int_value);


void __RPC_STUB IDynamicQueryContext_setVariableAsInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_setVariableAsString_Proxy( 
    IDynamicQueryContext * This,
    /* [in] */ BSTR varname,
    /* [in] */ BSTR str_value);


void __RPC_STUB IDynamicQueryContext_setVariableAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_setVariableAsDocumentFromFile_Proxy( 
    IDynamicQueryContext * This,
    /* [in] */ BSTR varname,
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri);


void __RPC_STUB IDynamicQueryContext_setVariableAsDocumentFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_deleteVariable_Proxy( 
    IDynamicQueryContext * This,
    /* [in] */ BSTR varname);


void __RPC_STUB IDynamicQueryContext_deleteVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_deleteAllVariables_Proxy( 
    IDynamicQueryContext * This);


void __RPC_STUB IDynamicQueryContext_deleteAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDynamicQueryContext_setContextItemAsDocumentFromFile_Proxy( 
    IDynamicQueryContext * This,
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri);


void __RPC_STUB IDynamicQueryContext_setContextItemAsDocumentFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDynamicQueryContext_INTERFACE_DEFINED__ */



#ifndef __ZorbaCOMApiLib_LIBRARY_DEFINED__
#define __ZorbaCOMApiLib_LIBRARY_DEFINED__

/* library ZorbaCOMApiLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ZorbaCOMApiLib;

EXTERN_C const CLSID CLSID_ZorbaSingleThread;

#ifdef __cplusplus

class DECLSPEC_UUID("6C2420BD-4924-4B62-B61E-69D563C74A78")
ZorbaSingleThread;
#endif
#endif /* __ZorbaCOMApiLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


