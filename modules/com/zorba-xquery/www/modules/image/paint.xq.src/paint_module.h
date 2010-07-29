/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ZORBA_IMAGEMODULE_PAINTMODULE_PAINTMODULE_H
#define ZORBA_IMAGEMODULE_PAINTMODULE_PAINTMODULE_H

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include "image_module.h"

namespace zorba {  namespace imagemodule { namespace paintmodule {

class PaintModule : public zorba::imagemodule::ImageModule 
{

  

  
public:
  
  virtual String
  getURI() const { return "http://www.zorba-xquery.com/modules/image/paint"; }
  
  virtual StatelessExternalFunction*
  getExternalFunction(String aLocalname) const;

    
};

} /* namespace paintmodule */
} /* namespace imagemodule */ 
} /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_PAINTMODULE_PAINTMODULE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
