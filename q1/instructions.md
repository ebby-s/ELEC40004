Programming for Engineers Portfolio : Quarter 1
===============================================

These exercises are minimal exercises intended to keep people
up to date, and also to provide some advance warning to the
teaching staff if people are having difficulty keeping up with
the practical skills. The word "portfolio" is not the best
choice of word, as it implies something that you show off to
demonstrate your skills. These exercises are much more
intended to demonstrate basic competency - everyone should
be able to solve them and do well.

Each week there will be a similar set of problems, and these
build up into a directory that will be submitted at the end
of the reading week (there will be no new portfolio exercises
during reading week.)

The exercises all live within a directory structure, and
your final submission will be a single file that collects
together your solution.

The exercises for each quarter are in a directory called `q1`,
and within that they are placed in sub-directories for each
week. They are organised into "sets" for each week, in order
to allow for numbering starting at 1; so each week goes
into directories `s1`, `s2`, `s3`, and so on. Your work for
each set will go into each directory, and you'll build up
the complete set as you go.

The script `prepare_submission.sh` is used to package up
your directories in a standard format. You can run it
by `cd`-ing to the direction and running it like a program:
```
./prepare_submission.sh
```
it should produce a single file called:
```
../ELEC40004-portfolio-es1219-DATE-TIME.tar.gz`
```
Notice that the file will be created in the parent directory,
and each time you run the script it will create a new file.
The `tar.gz` is similar to a zip file, and contains all your
submission files - you can actually use it as a simple form
of backup if you like. Please submit the file that comes out of
the script, as it ensures that directories are put in
the right places.

The description of each portfolio set is contained in the
`sN` directory (e.g. `s1`, `s2`, ...) directories, and will
build up as the weeks go by.

Instructions are available as [mark-down](https://en.wikipedia.org/wiki/Markdown),
which is a raw textual representation, or as pdfs that are
generated from the mark-down. Markdown files have the `.md`
file extension, and can be opened in any text editor.

You can do the portfolio whenever you like, and the only
requirement is that you submit the complete set at the end
of the reading week. No-one will be checking to see whether
you have done it before then, and you can choose to do it
whenever you like.

The blackboard submission system is set to open at 18:00 on Monday 4th,
with the assessment name "Q1PortfolioExercises".
A reminder: the delay is to encourage people to think about how
to manage and backup files, particularly when working with
laptops which might fail.

You can submit as many times as you like to blackboard, and
the last submission will be taken as your final submission.

### Sanity check : Mon 11th Nov at 9:00

On Monday 11th at 9:00 a copy of all the current submissions will be
grabbed, and some basic sanity checks will be run. These won't
perform a full assessment, but are intended to do some basic
"sanity checks" to make sure that the right type of file has
been submitted, and that everything is in roughly the right place.

### Final deadline : Fri 15th at 18:00

The final submission deadline is on Friday 15th  (at the end of reading week / mid-term) at 18:00.
