declare variable $y := (<a>1</a>,<a>2</a>,<a>3</a>,<a>4</a>,<a>5</a>,<a>6</a>,<a>7</a>,<a>8</a>,<a>9</a>,<a>10</a>);

declare context item := $y;

declare variable $x external := fn:last();

$x
