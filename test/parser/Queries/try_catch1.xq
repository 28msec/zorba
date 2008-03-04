try { 
  <a/> 
} 
catch (err:XPST0051) { 
  <b/> 
}
catch (err:XPST0080) {
  "text"
}
catch (*, $error) {
  "Error: " ,$error 
}
