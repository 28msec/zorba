import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";
declare namespace top10nl="http://www.kadaster.nl/top10nl";

geo:envelope((fn:doc("gmlsf_data.xml")/gml:FeatureCollection/gml:featureMembers/top10nl:Wegdeel/top10nl:geometrie/gml:Polygon)[1])
