# Full Text

The Zorba processor implements the
<a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0</a>
specification.
Additional documentation:
* [Stemmer](stemmer.md)
* [Thesaurus](thesaurus.md)
* [Tokenizer](tokenizer.md)
* <a href="/modules/latest/zorba.io/modules/full-text">Full Text Module</a>

## Unimplemented Features

The full text specification is mostly, but not completely, implemented.
The features that are not (completely) implemented are:
* The <a href="http://www.w3.org/TR/xpath-full-text-10/#ftignoreoption">Ignore Option</a>
  (bug <a href="https://github.com/28msec/zorba/issues/2">2</a>).
* <a href="http://www.w3.org/TR/xpath-full-text-10/#section-score-variables">Score Variables</a>
  and <a href="http://www.w3.org/TR/xpath-full-text-10/#section-using-weights">Using Weights Within a Scored FTContainsExpr</a>
  (bug <a href="https://github.com/28msec/zorba/issues/3">3</a>).

