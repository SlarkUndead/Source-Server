#ifndef DOMDeepNodeListImpl_HEADER_GUARD_
#define DOMDeepNodeListImpl_HEADER_GUARD_

/*
 * Copyright 2001-2002,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: DOMDeepNodeListImpl.hpp 176026 2004-09-08 13:57:07Z peiyongz $
 */

//
//  This file is part of the internal implementation of the C++ XML DOM.
//  It should NOT be included or used directly by application programs.
//
//  Applications should include the file <xercesc/dom/DOM.hpp> for the entire
//  DOM API, or xercesc/dom/DOM*.hpp for individual DOM classes, where the class
//  name is substituded for the *.
//

#include <../../../SceneEdit/Xerces/src/xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOMNodeList.hpp>

XERCES_CPP_NAMESPACE_BEGIN


class DOMNode;


class CDOM_EXPORT DOMDeepNodeListImpl: public DOMNodeList {
private:
    const DOMNode*   fRootNode;
    const XMLCh*     fTagName;
    bool             fMatchAll;
    int              fChanges;
    DOMNode*         fCurrentNode;
    XMLSize_t        fCurrentIndexPlus1;

    //DOM Level 2
    const XMLCh*     fNamespaceURI;
    bool		         fMatchAllURI;
    bool             fMatchURIandTagname; //match both namespaceURI and tagName

public:
    DOMDeepNodeListImpl(const DOMNode *rootNode, const XMLCh *tagName);
    DOMDeepNodeListImpl(const DOMNode *rootNode,	//DOM Level 2
	                    const XMLCh *namespaceURI,
                       const XMLCh *localName);
    virtual          ~DOMDeepNodeListImpl();
    virtual XMLSize_t getLength() const;
    virtual DOMNode*  item(XMLSize_t index) const;
    DOMNode*  cacheItem(XMLSize_t index);

private:
    DOMNode*          nextMatchingElementAfter(DOMNode *current);
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    DOMDeepNodeListImpl(const DOMDeepNodeListImpl &);
    DOMDeepNodeListImpl & operator = (const DOMDeepNodeListImpl &);   
};

XERCES_CPP_NAMESPACE_END

#endif