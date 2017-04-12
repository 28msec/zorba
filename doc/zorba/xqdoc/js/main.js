$(function(){
  var supportedModes = ["xml", "xquery"];
  $(".ace-static").each(function(k, v){
    var mode = $(v).attr("ace-mode");
    if(supportedModes.indexOf(mode) != -1) {
      var mode = require("ace/mode/" + mode).Mode;
      mode = new mode();
      var tokenizer = mode.$tokenizer;
      var source = $(v).text().split("\n");
      var state = "start";
      var content = "";
      $(source).each(function(n, l){
        tokens = tokenizer.getLineTokens(l, state);
        state = tokens.state;
        tokens = tokens.tokens;
        $(tokens).each(function(i, t){
          content += "<span class=\"" + t.type.replace("\.", " ") + "\">" + t.value.replace("<", "&lt;").replace(">", "&gt;")  + "</span>";   
        });
        content += "<br />";
      });
      $(v).empty();
      $(v).append(content);
    }
  });
});
