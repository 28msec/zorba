<?php
$boundary = "ML_BOUNDARY_4219471319962738285";

header("Content-Type: multipart/mixed; boundary=$boundary");

echo "--${boundary}\n";
echo "Content-Type: application/json\n";
echo "Content-Disposition: attachment; filename=\"/entities/0404b421-2615-48f4-8b2c-b5dea4b4a1c7.json\"; category=content; format=json\n";
echo "Content-Length: 739\n\n";
echo '{"_id":"0404b421-2615-48f4-8b2c-b5dea4b4a1c7", "EIDs":["http://info.edinet-fsa.go.jp E02166-000", "http://disclosure.edinet-fsa.go.jp E02166-000", "http://www.tse.or.jp/sicc 72670"], "Profiles":{"FSA":{"Name":"FSA", "TDNETCode":"72670", "EDINETCode":"E02166", "EntityKind":"Company", "SubmitterName":"本田技研工業株式会社", "SubmitterNameAlphabetic":"HONDA MOTOR CO., LTD.", "SubmitterNamePhonetic":"ホンダギケンコウギョウカブシキガイシャ", "SubmitterType":"内国法人・組合", "SecuritiesCode":"7267", "Province":"港区南青山二丁目１番１号", "Industry":"Transportation Equipments", "CapitalStock":86067, "AccountClosingDate":" 3.31", "IsListed":true, "IsConsolidated":true, "Tags":["NIKKEI"]}}}';
echo "\n";

echo "--${boundary}\n";
echo "Content-Type: application/json\n";
echo "Content-Disposition: attachment; filename=\"/entities/904afa41-372b-45b5-b2c9-ad8022b3796e.json\"; category=content; format=json\n";
echo "Content-Length: 749\n\n";
echo '{"_id":"0404b421-2615-48f4-8b2c-b5dea4b4a1c7", "EIDs":["http://info.edinet-fsa.go.jp E02166-000", "http://disclosure.edinet-fsa.go.jp E02166-000", ';
echo "\n";
echo '"http://www.tse.or.jp/sicc 72670"], "Profiles":{"FSA":{"Name":"FSA", "TDNETCode":"72670", "EDINETCode":"E02166", "EntityKind":"Company", "SubmitterName":"本田技研工業株式会社", ';
echo "\n";
echo '"SubmitterNameAlphabetic":"HONDA MOTOR CO., LTD.", "SubmitterNamePhonetic":"ホンダギケンコウギョウカブシキガイシャ", "SubmitterType":"内国法人・組合", "SecuritiesCode":"7267", "Province":"港区南青山二丁目１番１号", "Industry":"Transportation Equipments", "CapitalStock":86067, "AccountClosingDate":" 3.31", "IsListed":true, "IsConsolidated":true, "Tags":["NIKKEI"]}}}';
echo "\n";

echo "--${boundary}\n";
echo "Content-Type: image/jpeg\n\n";
echo file_get_contents('28io.jpeg');
echo "\n";

echo "--${boundary}--\n";

?>
