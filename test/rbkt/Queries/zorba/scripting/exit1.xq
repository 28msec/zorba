declare sequential function local:magic-trick() {
  exit returning ("magician's hat:", "rabbit");
  exit returning ("dead code"); 
};

declare sequential function local:professional-magician() {
  let $res := local:magic-trick()
  return
      exit returning $res;
};

local:professional-magician()

