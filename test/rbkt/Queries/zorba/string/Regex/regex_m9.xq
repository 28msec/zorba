let $poem := 
<poem author="Wilhelm Busch"> Kaum hat dies der Hahn gesehen,
        Fangt er auch schon an zu krahen: Kikeriki! Kikikerikih!! 
        Tak, tak, tak! - da kommen sie. 
</poem>
return
fn:matches($poem, "(tak.*){3}", "i")