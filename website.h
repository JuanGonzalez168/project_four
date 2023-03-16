//website.h
//Class: cs260
//Author: Juan Gonzalez
//Purpose: Class definition to build a website object 

#pragma once

#include <cstring>
#include <iostream>

class Website
{

public:

    Website();
    Website(const char* topic, const char* keyword, const char* summary, const char* review, const char* url, int rating);
    Website(const Website& a_website);
    ~Website();

    void setTopic(const char* topic);
    void setKeyword(const char* keyword);
    void setSummary(const char* summary);
    void setReview(const char* review);
    void setUrl(const char* url);
    void setRating(const int rating);

    const char* getTopic() const;
    const char* getKeyword() const;
    const char* getSummary() const;
    const char* getReview() const;
    const char* getUrl() const;
    int getRating() const;

    const Website& operator=(const Website& a_website);
    friend bool operator<(const Website& a_website2, const Website& a_website1);
    friend std::ostream& operator<< (std::ostream& out, const Website& a_website);
    

private:

    char* m_topic;
    char* m_keyword;
    char* m_summary;
    char* m_review;
    char* m_url;
    int m_rating; 
   
    
    void _allocateString(char*& dest, const char* src);
    void _destroyString(char*& src);

};
