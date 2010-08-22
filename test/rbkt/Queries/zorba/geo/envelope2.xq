import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";
declare default element namespace "http://www.adv-online.de/namespaces/adv/gid/4.0";

geo:envelope((fn:doc("gmlsf_data2.xml")/gml:FeatureCollection/gml:featureMember/AX_Strassenachse/position/gml:Curve)[1])
