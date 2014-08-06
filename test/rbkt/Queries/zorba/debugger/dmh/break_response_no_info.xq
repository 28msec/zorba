import module namespace dmh = "http://zorba.io/modules/dbgp-message-handler";

let $e :=
  <response command="status" status="break" reason="ok" transaction_id="5">
  </response>
return
  dmh:process($e)
