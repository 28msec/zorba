let $polozky := for $p in doc("5890.xml")//hospodarka/inventar/*
                return element polozka 
                       {
                         element meno {"Meno"},     
                         element cena { text { $p/@cena } }
                       }
        
let $artikeln := for $a in doc("5890.xml")//artikel
                 return element polozka { <polozka>{$a}</polozka> }
        
return <inventar>{$polozky union $artikeln}</inventar>

