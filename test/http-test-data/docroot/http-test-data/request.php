<?php

function emitMultipart($contentType)
{
  list ($type, $boundary) = split("; ", $contentType);
  $type = trim($type);
  $boundary = trim($boundary);
  list ($tmp, $boundary) = split("=", $boundary);
  $boundary = trim($boundary);
  $d = fopen("php://input", "r");
?>
  <http:multipart content-type="<? echo $type; ?>" boundary="<? echo $boundary; ?>">
<?
  $hasNext = false;
  do {
    $finish = false;
    $len = strlen($boundary) + 2;
    $contentType = "";
    $contentId = "";
    $contentDescription = "";
    # read the first empty line
    fgets($d);
    while (strcmp(($line = trim(fgets($d))), "") != 0) {
      # ignore the boundary, which should be the start of the
      # message
      if (strcmp($line, "--$boundary") == 0) {
        continue;
      }
      if (strcmp($line, "--$boundary--") == 0) {
        $finish = true;
        break;
      }
      list($key, $value) = split(":", $line);
      $key = trim($key);
      $value = trim($value);
      $value = str_replace("\"", "&#34;", $value);
      if ($key == "Content-Type") {
        $contentType = $value;
      } elseif ($key == "Content-ID") {
        $contentId = $value;
      } elseif ($key == "Content-Description") {
        $contentDescription = $value;
      }
?>
  <http:header name="<? echo $key; ?>" value="<? echo $value; ?>"/>
<?
    }
    if ($finish == false) {
      $hasNext = emitBody($contentType, $contentDescription, $contentId, $boundary, $d);
    }
  } while ($hasNext)
?>
  </http:multipart>
<?
    fclose($d);
}

function emitBody($contentType, $contentDescription, $contentId, $boundary, $d)
{
  if (strcmp($contentType, "") == 0) {
    return false;
  }
  $hasNext = false;
  if ($contentDescription != "" && $contentId != "") {
?>
  <http:body content-type="<?echo $contentType?>" description="<?echo $contentDescription?>" id="<?$contentId?>">
<?
  } elseif ($contentId != "") {
?>
  <http:body content-type="<?echo $contentType?>" id="<?$contentId?>">
<?
  } elseif ($contentDescription != "") {
?>
  <http:body content-type="<?echo $contentType?>" description="<?echo $contentDescription?>"> 
<?
  } else {
?>
  <http:body content-type="<?echo $contentType?>">
<?
  }
  if ($boundary == "") {
    if (substr($contentType,  0, 5) == "text/" || strstr($contentType, "xml")) {
      echo "<![CDATA[";
      while ($data = fread($d, 1024)) {
        echo $data;
      }
      echo "]]>";
    } else {
      while ($data = fread($d, 1024)) {
        echo base64_encode($data);
      }
    }
  } else {
    $len = strlen($boundary);
    $toText = substr($contentType,  0, 5) == "text/" || strstr($contentType, "xml");
    $buffer = "";
    while (false !== ($char = fgetc($d))) {
      if ($char == '-') {
        $str = fread($d, $len + 1);
        if (strcmp($str, "-$boundary") == 0) {
          $hasNext = true;
          break;
        }
        $buffer .= $char . $str;
      } else {
        $buffer .= $char;
      }
    }
    if ($toText) {
      echo $buffer;
    } else {
      echo base64_encode($buffer);
    }
  }
?>
  </http:body>
<?
  return $hasNext;
}

header("Content-Type: text/xml");

if (!function_exists('getallheaders')) 
{
    function getallheaders() 
    {
       foreach ($_SERVER as $name => $value) 
       {
           if (substr($name, 0, 5) == 'HTTP_') 
           {
               $headers[str_replace(' ', '-', ucwords(strtolower(str_replace('_', ' ', substr($name, 5)))))] = $value;
           }
       }
       return $headers;
    }
}
$contentType = "";
$contentDescription = "";
$contentId = "";
?>
<http:request xmlns:http="http://expath.org/ns/http-client"
              method="<?echo $_SERVER['REQUEST_METHOD'];?>"
              href="<?echo $_SERVER['HTTP_HOST']; echo $_SERVER['REQUEST_URI'];?>">
<?
foreach (getallheaders() as $name => $value) {
  if ($name == "Content-Type") {
    $contentType = $value;
  } else if ($name == "Content-Description") {
    $contentDescription = $value;
  } else if ($name == "Content-Id") {
    $contentType = $value;
  }
?>
  <http:header name="<?echo $name;?>" value="<?echo $value;?>"/>
<?
}
if ($_SERVER['REQUEST_METHOD'] == "POST" || $_SERVER['REQUEST_METHOD'] == "PUT") {
  if (substr($contentType, 0, 10) == "multipart/") {
    emitMultipart($contentType);
  } else {
    $d = fopen("php://input", "r");
    emitBody($contentType, $contentDescription, $contentId, "", $d);
    fclose($d);
  }
}
?>
</http:request>
