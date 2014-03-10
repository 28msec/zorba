declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

<missing-variable>
{
for $x in fn:doc($input-context)//*:input-file[count(@variable) = 0 and ./text() != "emptydoc"]
return string($x/../@name)
}
</missing-variable>
