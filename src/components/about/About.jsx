import './about.scss';
import TeamMember from '../../reusable/TeamMember/TeamMember';
import Grid from '@mui/material/Grid';
import { Container, Divider, Typography } from '@mui/material';

export default function About() {
  return (
    <Grid container p={5}>
      <Grid item xs={12}>
        <Typography
          variant='h5'
          component='p'
          m={5}
          sx={{
            background: '#00ADB5',
            boxShadow: '0 0 0 100vmax #00ADB5',
            clipPath: 'inset(0 -100vmax)',
            fontSize: { xs: ' 2rem', md: '3.5rem' },
            fontWeight: '800',
            color: '#EEEEEE',
            marginBottom: '5%',
          }}
        >
          Welcome
        </Typography>
        <Container className='header'>
          <Typography
            component='h1'
            sx={{ fontSize: { xs: ' 2.5rem', md: '4rem' } }}
          >
            At
            <span
              style={{ fontSize: '140%', color: '#00ADB5', fontWeight: '600' }}
            >
              TERYAQ
            </span>
            , We Believe Everyone Deserves To Have Medical Attention
          </Typography>
        </Container>
      </Grid>

      <Grid item xs={12} md={6} marginTop={5} className='colored-section'>
        <div className='text-wrapper'>
          <Typography
            variant='h4'
            component='p'
            m={5}
            sx={{ fontSize: { xs: ' 2rem', md: '3rem' }, fontWeight: '600' }}
          >
            Our Goal
          </Typography>

          <Typography variant='h5' component='p' m={5}>
            Imagine someone cares for you and faithfully nurses you with your
            regular medicines reminding you to take them in time, relentlessly
            without fail.
          </Typography>
          <Typography variant='h5' component='p' m={5}>
            Imagine the relief you get from the mental tension of remembering
            the medicine names their timings and the confusion whether medicine
            is taken or not , if someone takes care of it totally.
          </Typography>
        </div>
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        marginTop={{ md: 5, xs: 0 }}
        alignItems='center'
        className='colored-section'
      >
        <img
          src='https://img.freepik.com/free-photo/close-up-pills-time_23-2148550946.jpg?w=826&t=st=1681423496~exp=1681424096~hmac=30abf60f05cd7e3ac1671828343933e2958099e5499f75f3122b764971faf774'
          alt=''
        />
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        marginTop={{ md: 5, xs: 5 }}
        alignItems='center'
        sx={{display:{xs:"none",md:"block"}}}

      >
        <img
          src='https://static4.salsajeans.com/images/block1_4476.jpg?1619021489'
          alt=''
        />
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        marginTop={5}
        sx={{
          background: '#393E46',
          color: '#eee',
        }}
      >
        <div className='text-wrapper'>
          <Typography
            variant='h4'
            component='p'
            m={5}
            sx={{
              fontSize: { xs: ' 2rem', md: '3rem' },
              fontWeight: '600',
            }}
          >
            Design
          </Typography>

          <Typography variant='h5' component='p' m={5}>
            The Smart MedBox is made up of birchply with 30x20x8.5 cm size and
            is designed to cover broad spectrum of utilization. It is elegantly
            designed to hold medicine in various formats e pills, small size
            medicine boxes, vials, syringes, ointment tube, small powder packets
            etc.,. All the medicines are physically visible hence easy to
            identify their quantity for refilling.
          </Typography>
          <Typography variant='h5' component='p' m={5}>
            Audio Reminder Alarms are designed to draw the attention of the user
            with number of rings control and snooze time control The MedBox is
            equipped with LED indications in all the 6 chambers for picking the
            correct scheduled medicine when Alarm goes ON.{' '}
          </Typography>
        </div>
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        marginTop={{ md: 5, xs: 5 }}
        alignItems='center'
        sx={{display:{xs:"block",md:"none"}}}
      >
        <img
          src='https://static4.salsajeans.com/images/block1_4476.jpg?1619021489'
          alt=''
        />
      </Grid>
      <Grid item xs={12} md={6} marginTop={5} className='colored-section'>
        <div className='text-wrapper'>
          <Typography
            variant='h4'
            component='p'
            m={5}
            sx={{ fontSize: { xs: ' 2rem', md: '3rem' }, fontWeight: '600' }}
          >
            Application
          </Typography>

          <Typography variant='h5' component='p' m={5}>
            It is designed in a most simplistic way to provide ease of use by
            anyone conversant with mobile operation. Individual slots of the Box
            can be enabled or disabled based on Requirement. Medicine can be
            scheduled either on daily basis or a specific day in a week for a
            specific time.
          </Typography>
          <Typography variant='h5' component='p' m={5}>
            Medicine names can also be stored in the Box for display on
            Electronic display provided on the top of the Box. Medicine names
            can also be stored in the Box for display on Electronic display
            provided on the top of the Box.
          </Typography>
        </div>
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        marginTop={{ md: 5, xs: 0 }}
        alignItems='center'
        className='colored-section'
      >
        <img
          src='https://img.freepik.com/free-photo/medication-time-with-clipboard_23-2148550938.jpg'
          alt=''
        />
      </Grid>
      <Grid item xs={12} m={2} marginTop={5}>
        <Divider>
          {' '}
          <Typography variant='h3'>Team</Typography>
        </Divider>
      </Grid>
      <Grid item xs={12} md={12} lg={12}>
        <TeamMember
          name='Lorem ipsum'
          image='https://media.istockphoto.com/id/1007763808/photo/portrait-of-handsome-latino-african-man.jpg?s=612x612&w=0&k=20&c=XPL1ukeC99OY8HBfNa_njDujOPf9Xz4yCEOo7O3evU0='
          position='Lorem ipsum dolor'
          description='Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
        />
      </Grid>
      <Grid item xs={12} md={6} lg={4}>
        <TeamMember
          name='Lorem ipsum'
          image='https://media.istockphoto.com/id/1007763808/photo/portrait-of-handsome-latino-african-man.jpg?s=612x612&w=0&k=20&c=XPL1ukeC99OY8HBfNa_njDujOPf9Xz4yCEOo7O3evU0='
          position='Lorem ipsum dolor'
          description='Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
        />
      </Grid>
      <Grid item xs={12} md={6} lg={4}>
        <TeamMember
          name='Lorem ipsum'
          image='https://media.istockphoto.com/id/1007763808/photo/portrait-of-handsome-latino-african-man.jpg?s=612x612&w=0&k=20&c=XPL1ukeC99OY8HBfNa_njDujOPf9Xz4yCEOo7O3evU0='
          position='Lorem ipsum dolor'
          description='Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
        />
      </Grid>
      <Grid item xs={12} md={6} lg={4}>
        <TeamMember
          name='Lorem ipsum'
          image='https://media.istockphoto.com/id/1007763808/photo/portrait-of-handsome-latino-african-man.jpg?s=612x612&w=0&k=20&c=XPL1ukeC99OY8HBfNa_njDujOPf9Xz4yCEOo7O3evU0='
          position='Lorem ipsum dolor'
          description='Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
        />
      </Grid>
    </Grid>
  );
}
