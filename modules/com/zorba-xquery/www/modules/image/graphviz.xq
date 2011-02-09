(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

(:~
 : <p>Module that provides functions for generating SVG graphs.</p> 
 : 
 : <p>The module provides two function for generating graphs given in the :
 : <ul><li>DOT language (see <a href="http://www.graphviz.org/">
 : http://www.graphviz.org</a>)</li><li>or in the XML-based Graph eXchange
 : Language (see <a href="http://www.gupro.de/GXL/">http://www.gupro.de/GXL/</a>),
 : respectively.</li></ul>
 : Both functions use the Graphviz Visualization Library in order to
 : layout and render the graphs. As a result, both return a sequence
 : of (document)-nodes (one for each input graph). 
 : These nodes are instances of the Scalable Vector Graphics (SVG) format. 
 : SVG is a language for describing two-dimensional graphics and
 : graphical applications in XML. More information about SVG can
 : be found at <a href="http://www.w3.org/Graphics/SVG/">http://www.w3.org/Graphics/SVG/</a>.
 : As second parameters, both functions take a sequence of strings that
 : are parameters for the graph generation and rendering algorithms.
 : Currently, only the empty-sequence is allowed here. 
 : These parameters exist for future use.</p>
 : <p>Please note that this feature is only available on Unix-based 
 : platforms (i.e. not on Windows).</p>
 :
 : @author <a href="http://www.28msec.com/home/index">28msec</a>
 : @library <a href="http://www.graphviz.org/">Graphviz - Graph Visualization Software</a>
 :)
module namespace gr = "http://www.zorba-xquery.com/modules/image/graphviz";

(:~
 : GXL (1.0) 
 : Document Type Definition
 :)
import schema namespace gxl="http://www.gupro.de/GXL/gxl-1.0.xsd";

(:~
 : Layout one ore more graphs given in the DOT language and render
 : them as SVG. For example,
 :
 : <p><code>
 : dot("digraph mygraph { p -> q }", ())
 : </code></p>
 :
 : @param $dot A dot description of the graph to render.
 : @param $params Parameters to configure the layout and rendering
 :        process. Currently, only the empty-sequence is allowed here.
 : @return A graph for each item in the sequence given using the first
 :         parameter. The result sequence consists of items which are
 :         instance of the SVG data model.
 :)
declare function gr:dot(
    $dot as xs:string*,
    $params as xs:string*) as node()* external;

(:~
 : Layout one ore more graphs given in the GXL language and render
 : them as SVG.
 :
 : @param $gxl A GXL description of the graph to render.
 : @param $params Parameters to configure the layout and rendering
 :        process. Currently, only the empty-sequence is allowed here.
 : @return A graph for each item in the sequence given using the first
 :         parameter. The result sequence consists of items which are
 :         instance of the SVG data model.
 :)
declare function gr:gxl(
    $gxl as node()*,
    $params as xs:string*) as node()* external;
