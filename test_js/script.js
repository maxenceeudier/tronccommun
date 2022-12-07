var create = $('.create');
var tbody = $('tbody');
var lastRow = tbody.children().last();

create.click(function()
{
    var del = 0;

    tbody.append("<tr>\
                    <td><input type=\"text\" value=\"\" placeholder=\"your firstname here\"></td>\
                    <td><input type=\"text\" value=\"\" placeholder=\"your lastname here\"></td>\
                    <td><button type=\"button\" class=\"add\">Add</button></td>\
                </tr>");

    lastRow = tbody.children().last();

    var firstname;
    lastRow.children().first().children().keyup(
        function()
        {
            firstname = $(this).val();
        }
    ).keyup();

    var lastname;
    lastRow.children().first().next().children().keyup(
        function()
        {
            lastname = $(this).val();
        }
    ).keyup();
    
    lastRow.children().last().click(function()
    {
         if (del)
            $(this).parent().remove();

        if (firstname.length)
        {
            $(this).parent().children().first().children().remove();
            $(this).parent().children().first().append(firstname);
        }

        if (lastname.length)
        {
            $(this).parent().children().first().next().children().remove();
            $(this).parent().children().first().next().append(lastname);
        }

        if (firstname.length && lastname.length || !firstname.length && !lastname.length)
        {
            $(this).parent().children().last().children().remove();
            $(this).parent().children().last().append("<button type=\"button\" class=\"del\">Del</button>");
            del = 1;
        }
    });
});

