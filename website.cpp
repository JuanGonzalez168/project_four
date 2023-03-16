//website.cpp
//Class: cs260
//Author: Juan Gonzalez
//Purpose: Implementation file for the Website Class

#include "website.h"


Website::Website()
   : m_topic(nullptr), m_summary(nullptr), m_review(nullptr), m_url(nullptr), m_rating(0)
{}


Website::Website(const char* topic, const char* keyword, const char* summary, const char* review, const char* url, int rating)
   : m_topic(nullptr), m_keyword(nullptr), m_summary(nullptr), m_review(nullptr), m_url(nullptr), m_rating(rating)
{
    _allocateString(m_topic,topic);
    _allocateString(m_keyword,keyword);
    _allocateString(m_summary,summary);
    _allocateString(m_review,review);
    _allocateString(m_url,url);
}


Website::Website(const Website& a_website)
   : m_topic(nullptr), m_keyword(nullptr), m_summary(nullptr), m_review(nullptr), m_url(nullptr), m_rating(0)
{
    *this = a_website;
}


void Website::_allocateString(char*& dest, const char* src)
{
    if(src)
    {
        int buffer_size = strlen(src) + 1;
        dest = new char[buffer_size];
        strncpy(dest,src,buffer_size);
    }
}


Website::~Website()
{ 
    _destroyString(m_topic);
    _destroyString(m_keyword);
    _destroyString(m_summary);
    _destroyString(m_review);
    _destroyString(m_url);
}


void Website::_destroyString(char*& string)
{
    if(string)
    {
        delete [] string;
    }
    string = nullptr;
}


void Website::setTopic(const char* topic)
{
    _destroyString(m_topic);
    _allocateString(m_topic,topic);
}


void Website::setKeyword(const char* keyword)
{
    _destroyString(m_keyword);
    _allocateString(m_keyword,keyword);
}


void Website::setSummary(const char* summary)
{
    _destroyString(m_summary);
    _allocateString(m_summary,summary);
}


void Website::setReview(const char* review)
{
    _destroyString(m_review);
    _allocateString(m_review,review);
}


void Website::setUrl(const char* url)
{
    _destroyString(m_url);
    _allocateString(m_url,url);
}


void Website::setRating(const int rating)
{
    m_rating = rating;
}


const char* Website::getTopic() const
{
    return m_topic;
}


const char* Website::getKeyword() const
{
    return m_keyword;
}


const char* Website::getSummary() const
{
   return m_summary; 
}


const char* Website::getReview() const
{
    return m_review;
}


const char* Website::getUrl() const
{
    return m_url;
}


int Website::getRating() const
{
    return m_rating;
}


const Website& Website::operator=(const Website& a_website)
{
    if(this == &a_website) 
    {
        return *this;
    }

    setTopic(a_website.m_topic);
    setKeyword(a_website.m_keyword);
    setSummary(a_website.m_summary);
    setReview(a_website.m_review);
    setUrl(a_website.m_url);
    setRating(a_website.m_rating);

    return *this;
}


bool operator< (const Website& web1, const Website& web2)
{
    int result = strcmp(web1.getKeyword(), web2.getKeyword());
    return result < 0; 
}

std::ostream& operator<<(std::ostream& out, const Website& a_website)
{
    out << "====Website====\n"
        << "Topic: " << a_website.getTopic() << "\n"
        << "Keyword: " << a_website.getKeyword() << "\n"
        << "Summary: " << a_website.getSummary() << "\n"
        << "Review: " << a_website.getReview() << "\n"
        << "Url: " << a_website.getUrl() << "\n"
        << "Rating: " << a_website.getRating() << "\n";
    return out;
}




