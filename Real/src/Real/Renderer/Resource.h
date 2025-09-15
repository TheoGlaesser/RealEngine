#pragma once


class Resource
{
	const char* m_resourceName;
	const char* m_filepath;
public:
	char const * const getResourceName() {return m_resourceName;}
	void setResourceName(const char* name) { m_resourceName = name; }
};
