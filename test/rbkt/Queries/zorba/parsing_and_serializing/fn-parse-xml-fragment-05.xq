fn:parse-xml-fragment("<?xml version='1.0' encoding='UTF-8'?>
<!-- Comment-1 -->
<?a-pi pi-1?>
<!-- Comment-2 -->
<far-north> text-1A
    <!-- Comment-3 --> text-1B
    <?a-pi pi-2?> text-1C
  <north mark='n0'> text-2A
      <!-- Comment-4 --> text-2B
      <?b-pi pi-3?> text-2C
    <near-north> text-3A
      <far-west/> text-3B
      <west mark='w0' west-attr-1='w1' west-attr-2='w2' west-attr-3='w3'/> text-3C
      <near-west/> text-3D
      <center mark='c0' center-attr-1='c1' center-attr-2='c2' center-attr-3='c3'> text-4A
        <near-south-west/> text-4B
            <!--Comment-5--> text-4C
            <?a-pi pi-4?> text-4D
        <near-south> text-5A
          <south mark='s0' south-attr-1='s1' south-attr-2='s2'> text-6A
            <far-south/> text-6B
          </south> text-5B
        </near-south> text-4E
            <?c-pi pi-5?> text-4F
        <south-east mark='1se'/> text-4G
        <south-east mark='2se'/> text-4H
      </center> text-3E
      <near-east/> text-3F
      <east mark='e0'>Text in east</east> text-3G
      <far-east/> text-3H
    </near-north> text-2D
  </north> text-1D
</far-north>
<!-- Comment-6 -->
<?a-pi pi-6?>
<!-- Comment-7 -->
")
