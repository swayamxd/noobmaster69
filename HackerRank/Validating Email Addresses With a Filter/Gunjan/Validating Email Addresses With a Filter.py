import string

def fun(s):
    # return True if s is a valid email, else return False
    try:
        userName = s.split("@")[0]
        
        websiteName = s.split("@")[1].split(".")[0]
        
        extension = s.split("@")[1].split(".")[1]
    except:
        return False
    else:
        allowedUserName = string.digits + string.ascii_letters + '-' + '_'
        allowedWebsiteName = string.digits + string.ascii_letters
        if len(extension)>3 or len(userName)<1 or len(websiteName)<1:
            return False
        elif set(userName)-set(allowedUserName):
            return False
        elif set(websiteName)-set(allowedWebsiteName):
            return False
        else:
            return True

def filter_mail(emails):
    return list(filter(fun, emails))

if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())

filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)