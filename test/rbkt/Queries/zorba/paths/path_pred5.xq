

(:
   Make sure that the positional pred is not pushed down and that there is
   no node sort/distinct.
:)

(

<root1>
  <a id="1">
      <b>
          <c/>
          <c><d/><d/></c>
      </b>
      <b>
          <c><d/></c>
      </b>
  </a>
</root1>

/a/b/c

)

[2]/d
