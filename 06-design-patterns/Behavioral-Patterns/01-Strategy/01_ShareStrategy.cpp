#include<iostream>
using namespace std;

class ShareStrategy
{
public:
    virtual void share() const = 0;
};

class Text : public ShareStrategy
{
public:
    void share() const override
    {
        cout << "Sharing though text.\n";
    }
};

class Email : public ShareStrategy
{
public:
    void share() const override
    {
        cout << "Sharing though email.\n";
    }
};

class Social : public ShareStrategy
{
public:
    void share() const override
    {
        cout << "Sharing though social.\n";
    }
};

class PhoneCameraApp
{
private:
    ShareStrategy *method;
public:
    PhoneCameraApp(ShareStrategy *method= nullptr):
        method(method)
    {

    }

    void setShareStrategy(ShareStrategy *method)
    {
        // cout << "Object is deleted\n";
        delete this->method;
        this->method = method;

    }

    void share()
    {
        cout << "Not sure how it'll do it ... ";
        method->share();
    }

    void take()
    {
        cout << "Cheese!\n";
    }

    virtual void edit() const = 0;

    void save()
    {
        cout << "Loading ... Image saved\n";
    }

    ~PhoneCameraApp()
    {
        // cout << "Object is deleted\n";
        delete this->method;
    }
};

class BasicCameraApp : public PhoneCameraApp
{
public:
    BasicCameraApp()
        {
        }
    void edit() const override
    {
        cout << "Normal editing features\n";
    }
};

class CameraPlusApp : public PhoneCameraApp
{
public:
    void edit() const override
    {
        cout << "Premium editing features\n";
    }
};

void NormalClient()
{
    BasicCameraApp *app = new BasicCameraApp();
    app->setShareStrategy(new Text);
    app->share();

    app->setShareStrategy(new Email);
    app->share();

    app->setShareStrategy(new Social);
    app->share();

    app->edit();
    app->save();
    app->take();

    delete app;
}

void PremiumClient(){
    CameraPlusApp *app = new CameraPlusApp();
    app->setShareStrategy(new Text);
    app->share();

    app->setShareStrategy(new Email);
    app->share();

    app->setShareStrategy(new Social);
    app->share();

    app->edit();
    app->save();
    app->take();

    delete app;
}

int main(){
    NormalClient();
    PremiumClient();

    return 0;
}
