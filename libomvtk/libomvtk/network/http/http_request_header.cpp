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
#include "http_request_header.h"
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

namespace omvtk
{

	HTTPRequestHeader::HTTPRequestHeader(LLURI const & uri_, 
									     String const & method_,
										 String const & http_version_)
	: HTTPHeader()
	, m_method(method_)
	, m_uri(uri_.get().getPathAndQuery())
	, m_http_version(http_version_)
	{	
		host() = uri_.get().getHost();
		if(uri_.get().getPort() != 0)
		{
			host() += ":" + boost::lexical_cast<String>(uri_.get().getPort());
		}
	}

	HTTPRequestHeader::HTTPRequestHeader(String const & host_, 
									 	 String const & request_uri_,
						  				 String const & method_,
										 String const & http_version_)
	: HTTPHeader()
	, m_method(method_)
	, m_uri(request_uri_)
	, m_http_version(http_version_)
	{
		host() = host_;
	}

	HTTPRequestHeader::HTTPRequestHeader(String const & host_, 
					  					 String const & port_, 
										 String const & request_uri_,
										 String const & method_,
										 String const & http_version_)
	: HTTPHeader()
	, m_method(method_)
	, m_uri(request_uri_)
	, m_http_version(http_version_)
	{
		host() += host_ + ":" + port_;		
	}

	HTTPRequestHeader::HTTPRequestHeader(HTTPRequestHeader const & hrh)
	: HTTPHeader(hrh)
	, m_method(hrh.m_method)
	, m_uri(hrh.m_uri)
	, m_http_version(hrh.m_http_version)
	{}

	HTTPRequestHeader::~HTTPRequestHeader()
	{
	}

	HTTPRequestHeader & HTTPRequestHeader::operator=(HTTPRequestHeader hrh)
	{
		swap(hrh);
		return *this;
	}

	void HTTPRequestHeader::swap(HTTPRequestHeader & hrh)
	{
		HTTPHeader::swap(hrh);
		m_method.swap(hrh.m_method);
		m_uri.swap(hrh.m_uri);
		m_http_version.swap(hrh.m_http_version);
	}

	String const & HTTPRequestHeader::version() const
	{
		return m_http_version;
	}

	String & HTTPRequestHeader::version()
	{
		return m_http_version;
	}
	String const & HTTPRequestHeader::method() const
	{
		return m_method;
	}
	
	String & HTTPRequestHeader::method()
	{
		return m_method;
	}

	String const & HTTPRequestHeader::uri() const
	{
		return m_uri;
	}
	
	String & HTTPRequestHeader::uri()
	{
		return m_uri;
	}
	

	String const & HTTPRequestHeader::accept() const
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT);
	}
	
	String & HTTPRequestHeader::accept()
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT);
	}
	
		
	String const & HTTPRequestHeader::accept_charset() const
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_CHARSET);
	}
	
	String & HTTPRequestHeader::accept_charset()
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_CHARSET);
	}
	

	String const & HTTPRequestHeader::accept_encoding() const
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_ENCODING);
	}
	
	String & HTTPRequestHeader::accept_encoding()
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_ENCODING);
	}
	
		
	String const & HTTPRequestHeader::accept_language() const
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_LANGUAGE);
	}
	
	String & HTTPRequestHeader::accept_language()
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT_LANGUAGE);
	}
	
	
	String const & HTTPRequestHeader::authorization() const
	{
		return field(HTTP::REQUEST::FIELD::AUTHORIZATION);
	}
	
	String & HTTPRequestHeader::authorization()
	{
		return field(HTTP::REQUEST::FIELD::AUTHORIZATION);
	}
	

	String const & HTTPRequestHeader::expect() const
	{
		return field(HTTP::REQUEST::FIELD::EXPECT);
	}
	
	String & HTTPRequestHeader::expect()
	{
		return field(HTTP::REQUEST::FIELD::ACCEPT);
	}
	
		
	String const & HTTPRequestHeader::from() const
	{
		return field(HTTP::REQUEST::FIELD::FROM);
	}
	
	String & HTTPRequestHeader::from()
	{
		return field(HTTP::REQUEST::FIELD::FROM);
	}
	
		
	String const & HTTPRequestHeader::host() const
	{
		return field(HTTP::REQUEST::FIELD::HOST);
	}
	
	String & HTTPRequestHeader::host()
	{
		return field(HTTP::REQUEST::FIELD::HOST);
	}
	
		
	String const & HTTPRequestHeader::proxy_authorization() const
	{
		return field(HTTP::REQUEST::FIELD::PROXY_AUTHORIZATION);
	}
	
	String & HTTPRequestHeader::proxy_authorization()
	{
		return field(HTTP::REQUEST::FIELD::PROXY_AUTHORIZATION);
	}
	

	String const & HTTPRequestHeader::user_agent() const
	{
		return field(HTTP::REQUEST::FIELD::USER_AGENT);
	}
	
	String & HTTPRequestHeader::user_agent()
	{
		return field(HTTP::REQUEST::FIELD::USER_AGENT);
	}
	

	String const & HTTPRequestHeader::referer() const
	{
		return field(HTTP::REQUEST::FIELD::REFERER);
	}
	
	String & HTTPRequestHeader::referer()
	{
		return field(HTTP::REQUEST::FIELD::REFERER);
	}
	

	String HTTPRequestHeader::request_line() const	
	{
		return m_method + " " + m_uri + " " + m_http_version + "\r\n";
	}

	String HTTPRequestHeader::request() const
	{
		String req = request_line();
		typedef std::pair<String,String> const PairT;
		BOOST_FOREACH(PairT & p, m_fields)
		{
			if(!p.first.empty() && !p.second.empty())
			{
				req += p.first + ": " + p.second + "\r\n";
			}
		}
		return req + "\r\n";
	}
}

