declare default element namespace "ns1";

namespace-uri (<a xmlns="ns1">{element b {}}</a>//b), namespace-uri (<a xmlns="ns2">{element b {}}</a>//*:b), (<a xmlns="ns3">{namespace-uri-from-QName (xs:QName ("b"))}</a>/text())
