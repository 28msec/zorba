import module namespace dmh = "http://zorba.io/modules/dbgp-message-handler";

let $e := <response command="status" status="break" reason="ok" transaction_id="5">dmh:process#1 at file.xq:10</response>
return
  dmh:process($e)
