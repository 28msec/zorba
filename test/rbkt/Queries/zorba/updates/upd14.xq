import schema namespace f = "http://www.evaluescience.com/schemas/forms" at "forms.xsd";

declare namespace an = "http://www.zorba-xquery.com/annotations";

declare %an:no-cache %an:sequential function local:test2() 
{
   variable $form := validate strict {
     <f:form>
       <f:hidden name="myid" value="3"/>
     </f:form>
   };

   replace value of node $form/f:hidden/@value with "hello";

   "ok"
};


local:test2()
