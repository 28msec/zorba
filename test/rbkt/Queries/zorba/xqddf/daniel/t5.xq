import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";


init:create-collection($xqddf-test:white-collection, (<wb>1</wb>,<wb>2</wb>,<wb>3</wb>,<wb>4</wb>,<wb>5</wb>,<wb>6</wb>,<wb>7</wb>,<wb>8</wb>,<wb>9</wb>,<wb>10</wb>));

init:create-collection($xqddf-test:blue-collection, (<bb>1</bb>,<bb>2</bb>,<bb>3</bb>,<bb>4</bb>,<bb>5</bb>,<bb>6</bb>,<bb>7</bb>,<bb>8</bb>,<bb>9</bb>,<bb>10</bb>));

manip:delete-nodes-first($xqddf-test:white-collection, 10 cast as xs:unsignedLong);

manip:collection($xqddf-test:white-collection)
