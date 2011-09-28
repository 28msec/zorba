let $x :=
  <p xml:lang="en">
    <span>good girl</span>
    <span xml:lang="es">chica bueno</span>
  </p>
return $x contains text "chico"
  using language "es"
  using stemming
