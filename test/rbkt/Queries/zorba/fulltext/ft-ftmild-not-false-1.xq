let $x :=
  <books>
    <book number="1">
      <title shortTitle="Improving Web Site Usability">Improving  
          the Usability of a Web Site Through Expert Reviews and
          Usability Testing</title>
      <author>Millicent Marigold</author>
      <author>Montana Marigold</author>
      <editor>Véra Tudor-Medina</editor>
      <content>
        <p>The usability of a Web site is how well the  
            site supports the users in achieving specified  
            goals. A Web site should facilitate learning,  
            and enable efficient and effective task  
            completion, while propagating few errors.
        </p>
        <note>This book has been approved by the Web Site  
            Users Association.
        </note>
      </content>
    </book>
  </books>
return $x contains text "web" not in "web site"
