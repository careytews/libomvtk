// vim:et:st=4:ts=4:sts=4:
// Copyright (c) 2008,2009 by the OpenMetaverse Toolkit Library Team
// All rights reserved.
//
// - Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// - Neither the name of the OpenMetaverse Toolkit Library Team nor the names
//   of its contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE
#ifndef GUARD_LIBOMVTK_NETWORK_HTTP_REQUEST_H_INCLUDED
#define GUARD_LIBOMVTK_NETWORK_HTTP_REQUEST_H_INCLUDED

#include "http_request_header.h"

namespace omvtk
{
	struct HTTPRequest
	{
		HTTPRequest(LLURI const & uri, 
				    String const & method = HTTP::METHOD::GET,
				    String const & http_version = HTTP::VERSION11);

		HTTPRequest(String const & host, 
				    String const & request_uri,
					String const & method,
					String const & http_version = HTTP::VERSION11);

		HTTPRequest(String const & host, 
				    String const & port, 
				    String const & request_uri,
				    String const & method,
				    String const & http_version = HTTP::VERSION11);
		
		HTTPRequest(HTTPRequest const &);
		~HTTPRequest();
		
		HTTPRequest & operator=(HTTPRequest);
		void swap(HTTPRequest &);

		HTTPRequestHeader & header();	
		HTTPRequestHeader const & header() const;	
		
		ByteBuffer & content();
		ByteBuffer const & content() const;

		void build(ByteBuffer & buf) const;
	protected:
		HTTPRequestHeader m_header;
		ByteBuffer m_content;
	};
}

#endif //GUARD_LIBOMVTK_NETWORK_HTTP_REQUEST_H_INCLUDED

