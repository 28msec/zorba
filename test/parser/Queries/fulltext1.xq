declare ft-option using language "ro";
declare ft-option using stemming;
declare ft-option using case sensitive;
declare ft-option using case insensitive;
declare ft-option using stop words at "uri" except at "uri";
declare ft-option using stop words ("uri") union at "uri";

for $i score $s in ()
let score $s := 123
return
  1 to 3 contains text
  ftnot "" not in "" ftand
    ("" ftor ftnot "" not in ftnot(""))
     ftand
      (#i:am not a ghost#) {  }
      ftand
      (#i:am a ghost#) { "boooh!" }
    ftand
    "" occurs at least $least times
    ftor
    "" occurs at most most times
    ftor
    "" occurs exactly times times
    ftor
    "" occurs exactly exactly times
    ftor
    "" occurs from least to most times
    ftor
    ""
      using language "ro"
      using wildcards
      using no wildcards
      using thesaurus at "uri" relationship "a string" exactly 3 levels
      using thesaurus default
      using thesaurus (at "")
      using thesaurus (default, at "" relationship "" from 3 to 4 levels, at "" at most 3 levels)
      using no thesaurus
      using stemming
      using no stemming
      using case sensitive
      using case insensitive
      using lowercase
      using uppercase
      using diacritics insensitive
      using diacritics sensitive
      using stop words default
      using stop words at "uri"
      using stop words ("")
      using stop words ("my", "words")
      using no stop words
      using option my:option "string"
    weight { expr }
  ordered
  window $words words window sentences sentences window paragraphs paragraphs
  distance exactly words words
  distance exactly paragraph sentences
  distance exactly sentences paragraphs
  distance at least distance words
  distance at least distance sentences
  distance at least distance paragraphs
  distance at most 1 words
  distance at most 2 sentences
  distance at most () paragraphs
  distance from $words to $sentences sentences
  distance from $words to $sentences words
  distance from () to . paragraphs
  same paragraph
  different paragraph
  at start
  at end
  entire content
  without content ("" | "")
