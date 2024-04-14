#include <iostream>
#include <vector>
#include <string>
#include <ctime>


using namespace std;

class Blog {
private:
    string name;
    string creationDate;
    string author;
    string theme;
    string bloggerDescription;
    int subscribersCount;
public:
    // Конструкторы
    Blog() : name(""), creationDate(""), author(""), theme(""), bloggerDescription(""), subscribersCount(0) {}

    Blog(string name, string creationDate, string author, string theme, string bloggerDescription, int subscribersCount)
        : name(name), creationDate(creationDate), author(author), theme(theme), bloggerDescription(bloggerDescription), subscribersCount(subscribersCount) {}

    Blog(const Blog& other)
        : name(other.name), creationDate(other.creationDate), author(other.author), theme(other.theme), bloggerDescription(other.bloggerDescription), subscribersCount(other.subscribersCount) {}
    ~Blog() {}

    // Методы доступа
    string getName() const { return name; }
    string getCreationDate() const { return creationDate; }
    string getAuthor() const { return author; }
    string getTheme() const { return theme; }
    string getBloggerDescription() const { return bloggerDescription; }
    int getSubscribersCount() const { return subscribersCount; }

    // Методы поиска
    vector<Blog> findByTheme(const string& theme) const;
    Blog findOldest() const;
    Blog findNewest() const;
};

// Метод поиска блогов определенной тематики
vector<Blog> Blog::findByTheme(const string& theme) const 
{
    vector<Blog> foundBlogs;
    if (theme == this->theme) 
    {
        foundBlogs.push_back(*this);
    }
    return foundBlogs;
}

// Метод поиска самого старого блога
Blog Blog::findOldest() const 
{
    return *this;
}

Blog Blog::findNewest() const 
{
    return *this;
}

int HeadFunction_1() 
{
    vector<Blog> blogs;
    string name, creationDate, author, theme, bloggerDescription;
    int subscribersCount;
    int numBlogs;

    cout << "Enter the number of blogs: ";
    cin >> numBlogs;

    for (int i = 0; i < numBlogs; ++i) 
    {
        cout << "Enter name of blog " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter creation date of blog " << i + 1 << " (YYYY-MM-DD): ";
        cin >> creationDate;

        cout << "Enter author of blog " << i + 1 << ": ";
        cin.ignore();
        getline(cin, author);

        cout << "Enter theme of blog " << i + 1 << ": ";
        getline(cin, theme);

        cout << "Enter blogger description of blog " << i + 1 << ": ";
        getline(cin, bloggerDescription);

        cout << "Enter subscribers count of blog " << i + 1 << ": ";
        cin >> subscribersCount;

        blogs.push_back(Blog(name, creationDate, author, theme, bloggerDescription, subscribersCount));
    }

    // Поиск всех блогов определенной тематики
    string searchTheme;
    cout << "\nEnter the theme to search: ";
    cin.ignore();
    getline(cin, searchTheme);

    vector<Blog> foundBlogs;
    for (const Blog& blog : blogs) 
    {
        vector<Blog> result = blog.findByTheme(searchTheme);
        foundBlogs.insert(foundBlogs.end(), result.begin(), result.end());
    }

    if (!foundBlogs.empty()) {
        cout << "\nBlogs found with theme \"" << searchTheme << "\":" << endl;
        for (const Blog& blog : foundBlogs)
        {
            cout << "Name: " << blog.getName() << ", Author: " << blog.getAuthor() << ", Creation Date: " << blog.getCreationDate() << endl;
        }
    }
    else 
    {
        cout << "\nNo blogs found with theme \"" << searchTheme << "\"." << endl;
    }

    // Поиск самого старого блога и самого нового
    if (numBlogs > 1)
    {
        Blog oldestBlog = blogs[0].findOldest();
        for (int i = 1; i < blogs.size(); ++i) 
        {
            Blog currentOldest = blogs[i].findOldest();
            if (currentOldest.getCreationDate() < oldestBlog.getCreationDate())
            {
                oldestBlog = currentOldest;
            }
        }

        cout << "\nOldest blog:" << endl;
        cout << "Name: " << oldestBlog.getName() << ", Author: " << oldestBlog.getAuthor() << ", Creation Date: " << oldestBlog.getCreationDate() << endl;

        Blog newestBlog = blogs[0].findNewest();
        for (int i = 1; i < blogs.size(); ++i)
        {
            Blog currentNewest = blogs[i].findNewest();
            if (currentNewest.getCreationDate() > newestBlog.getCreationDate()) 
            {
                newestBlog = currentNewest;
            }
        }
        cout << "\nNewest blog:" << endl;
        cout << "Name: " << newestBlog.getName() << ", Author: " << newestBlog.getAuthor() << ", Creation Date: " << newestBlog.getCreationDate() << endl;
    }

    return 0;
}
