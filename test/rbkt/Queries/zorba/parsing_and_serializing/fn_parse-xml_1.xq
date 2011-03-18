let $message := fn:parse-xml("<?xml version='1.0'?>
<soap:Envelope xmlns:soap='http://www.w3.org/2003/05/soap-envelope'>
  <soap:Header>
    <so:transaction xmlns:so='http://www.28msec.com/templates/soap/stockorder'
                    soap:mustUnderstand='1'
                    soap:actor='http://www.28msec.com/ordersystem'
                    soap:encodingStyle='http://www.w3.org/2001/12/soap-encoding'>
      75548
    </so:transaction>
  </soap:Header>
  <soap:Body>
    <system:order xmlns:o='http://www.28msec.com/ordersystem'
                  soap:encodingStyle='http://www.w3.org/2001/12/soap-encoding'>
      <system:isin>CH0010570767</system:isin>
      <system:qty>1000</system:qty>
    </system:order>
  </soap:Body>
</soap:Envelope>")
return $message
