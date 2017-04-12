# ${info.title}
*Version ${info.version}*

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
| Name | Located in | Description | Required | Type |
| ---- | ---------- | ----------- | -------- | ---- |<% _.forEach(op.parameters, function(param){ %>
| **${param.name}** | `${param.in}` | <% print(param.description.replace(/\n/g, ' ')) %> | `${param.required}` | `${param.type}` |<%}); %>

#### Responses
| Name | Description |
| ---- | ----------- |<% _.forEach(op.responses, function(resp, code){ %>
| **${code}** | ${resp.description} |<% }); %>

        <%
    });
});
%>
