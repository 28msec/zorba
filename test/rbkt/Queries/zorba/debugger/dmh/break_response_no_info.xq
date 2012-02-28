import module namespace dmh = "http://www.zorba-xquery.com/modules/debugger/dbgp-message-handler";

let $e :=
  <response command="status" status="break" reason="ok" transaction_id="5">
  </response>
return
  dmh:process($e)
