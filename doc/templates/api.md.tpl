# ${info.title}
${info.description}

<%
_.forEach(paths, function(path, url){
    print("## " + url + "\n");
    _.forEach(path, function(op, method){
        print("### " + method.toUpperCase() + "\n");
        %>
${op.summary}

${op.description}

#### Parameters
| Name | Located in | Description | Default | Required | Type |
| ---- | ---------- | ----------- | ------- | -------- | ---- |<% _.forEach(op.parameters, function(param){ %>
| ${param.name} | ${param.in} | ${param.description.replace("\n", " ")} | `<% param.default %>` | `${param.required}` | `${param.type}` |<%}); %>

#### Responses
        <%
    });
});
%>
