declare variable $input-context external;
let $doc := doc($input-context)
let $authorsAll  := count(distinct-values($doc//author))
let $papersAll   := count($doc/dblp/inproceedings)
return 
    <statistics>
       <total>
         <paper>{$papersAll}</paper>
         <author>{$authorsAll}</author>
       </total>
       <conferences>{
         for $conference  in ("EDBT", "ICDT", "ICDE", "PODS", "VLDB", "SIGMOD Conference")
         let $authorCount := count(distinct-values(doc("dblp_conf.xml")/dblp/
                             inproceedings[booktitle = $conference]/author))
         let $paperCount  := count(doc("dblp_conf.xml")/dblp/
                             inproceedings[booktitle = $conference])
         return
           <conference><name>{$conference}</name>
                       <paper>{$paperCount}</paper>
                       <author>{$authorCount}</author>
                       </conference>
         }
       </conferences>
    </statistics>

(: q0: saxon: 1.5 :)
