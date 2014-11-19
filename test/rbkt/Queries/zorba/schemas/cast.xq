import schema namespace tt = "http://www.onvif.org/ver10/schema" at "castable.xsd";
variable $document := doc("castable.xml");

$document/*:NotificationMessageHolderType/*:Message/tt:Message/tt:Source/tt:SimpleItem[@Name="Token"]/@Value cast as tt:ReferenceToken