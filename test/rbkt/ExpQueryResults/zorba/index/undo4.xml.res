<?xml version="1.0" encoding="UTF-8"?>
<person id="1"><car make="honda"/><car make="vw"/></person><person id="2"><car make="vw"/></person>

TEST 0:

<exception>err:XPTY0004 : node with more than one key value found during probe on index "f:PersonCars"</exception>

TEST 1:

<exception>zerr:ZDDY0024 : "f:PersonId": index uniqueness violation</exception>
<person id="1"><car make="honda"/><car make="vw"/></person><person id="2"><car make="vw"/></person>

TEST 2:

<exception>zerr:ZDDY0024 : "f:PersonId": index uniqueness violation</exception>
<person id="1"><car make="honda"/><car make="vw"/></person><person id="2"><car make="vw"/></person>

TEST 3:

<exception>zerr:ZDDY0024 : "f:PersonId": index uniqueness violation</exception>
<person id="1"><car make="honda"/><car make="vw"/></person><person id="2"><car make="vw"/></person>

TEST 4:

<person id="1"><car make="vw"/></person><person id="2"><car make="vw"/></person>
