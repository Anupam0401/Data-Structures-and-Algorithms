
NOTE:-
##Please read the readMeFirst_myProblem.txt first before beggining to use the app by following steps mentioned below. 
#The google script code contains neccesery comments near the code(either above or right of it) and , comments right of the if or else statement represent their working when they are executed.
#The spreadsheet(sample spreadsheet) has been attached which is able to generate the form as well as script related to it .
  Hence, a seperate Google Form has not been attached but the script editor code has been attached with name 'appCode.txt'. for easy access to it.
#The instructions provided can be followed to run the application by any user even without prior knowlege of Google App Script.Please follow it to run the application.
#The document contains the brief description of the built-in functions used in my code.
#I had created the Google form and spreadsheet without using institute email-ID(anupamk@iitbhilai.ac.in) but this email-ID has been shared both of those and aloowed permission to edit.
#Please ignore the responses filled in the spreadsheet attached. The entries are totally random. 


The instructions to run the Google Script Application made by me are as follows:-

1. Firstly, open the Google forms from 'forms.google.com' and add the short answer questions mentioned in the spreadsheet, in the same sequence as shown in the sample spreadsheet attached with this file.
   Remember to mark each questions as 'required' in the Google form. For reference, open the sample spreadsheet attached , select 'Form' and click on 'Go to Live Form' to see how your form should look.
2. Attach a spreadsheet to this form which is going to store the responses filled in the google form by going to the 'response' window and clicking the create spreadsheet icon(shown as white '+' symbol on green background).
3. As we attach the spreadsheet, the headings of the spreadsheet automatically gets filled with the questions sited in the google form created earlier.
4. Now in the spreadsheet, look over to the menu where you can easily spot 'Tools' , click it and open '<>Script Editor' from the dropdown menu obtained.
5. After the Script Editor opens, copy the text code from 'appCode.txt' attached along with this file and paste it in the script Editor replacing everything initially present in it.
6. Save the 'code.gs' file and name the script according to your choice.
7. Now we have to add trigger to the current project by clicking on 'timer icon' (right of save icon) or, from 'Edit' , choose "current project's triggers".
8. You will be brought to a page showing triggers for the current page, and will not show any added triggers initially so, click on "+Add Trigger" on the right bottom of that page.
9. A form opens where you just have to change the 'event type' located at the bottom. Click on it and select 'On form submit' from the dropdown menu and click on 'Save'.
10. You may be required to verify your email address and password and allow the app to access your account (by clicking on Advanced and continuing to allow) . After doing this successfully, you will be shown a trigger marked by light blue colour.
11. After trigger is added, go back to the script Editor and save it.
12. Before beginning to run the code , first fill out a response of the form created by you, by going to the 'Form' in your spreadsheet and selecting 'Go to live form' and filling out the form.
    You may also fill response by going to 'Form' in the top bar of your spreadsheet and selecting 'Send form' and choose neccesery option according to your choice.
13. After the form is successfully submitted, get back to the script Editor and save it. Once again , you may be required to authorise your account, allow it as done earlier and saving is complete.
14. If you have done everything correctly, you're sure to get your response on the email-Id, you filled out in the form.
15. Now you can fill out more responses from the procedure described above(in 12) or you can directly go to form you created and in the responses window of it, click on 'send' and send it to someone via different options clearly stated there.
16. The spreadsheet keeps track of all the responses being filled out using your form and also perform the demanded tasks(in Q1) automatically.
 

 