import './about.scss';
import TeamMember from '../../reusable/TeamMember/TeamMember';
import Grid from '@mui/material/Grid';
import { Container, Divider, Typography } from '@mui/material';
import profileImage from '../../assets/profile image.png';
import omarSobhy from '../../assets/omar sobhy.jpg';
import ahmedHafez from '../../assets/ahmed hafez.jpg';
import abdulrahmanMohammed from '../../assets/abdulrahman mohammed.jpeg';
import mohamedAshraf from '../../assets/mohamed ashraf.png';

export default function About() {
  return (
    <Grid container className='about-container'>
      <Grid item xs={12}>
        {/* <Typography
          variant="h5"
          component="h3"
          className="welcome"
         
        >
          Welcome
        </Typography> */}
        <Container className='header'>
          <Typography component='h1'>
            At <span className='about-title'>TERYAQ</span>, We Believe Everyone
            Deserves To Have Medical Attention
          </Typography>
        </Container>
      </Grid>

      <Grid item xs={12} md={6} className='colored-section grid-item'>
        <div className='text-wrapper'>
          <Typography variant='h4' component='h4'>
            Our Goal
          </Typography>

          <Typography variant='h5' component='h5'>
            Imagine someone cares for you and faithfully nurses you with your
            regular medicines reminding you to take them in time, relentlessly
            without fail.
          </Typography>
          <Typography variant='h5' component='h5'>
            Imagine the relief you get from the mental tension of remembering
            the medicine names their timings and the confusion whether medicine
            is taken or not , if someone takes care of it totally.
          </Typography>
        </div>
      </Grid>
      <Grid item xs={12} md={6} className='colored-section grid-item'>
        <img
          src='https://img.freepik.com/free-photo/close-up-pills-time_23-2148550946.jpg?w=826&t=st=1681423496~exp=1681424096~hmac=30abf60f05cd7e3ac1671828343933e2958099e5499f75f3122b764971faf774'
          alt=''
        />
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        className='grid-item'
        sx={{ display: { xs: 'none', md: 'block' } }}
      >
        <img
          src='https://static4.salsajeans.com/images/block1_4476.jpg?1619021489'
          alt=''
        />
      </Grid>
      <Grid item xs={12} md={6} className='grid-item dark-section text-wrapper'>
        <Typography variant='h4' component='h4'>
          Design
        </Typography>

        <Typography variant='h5' component='h5'>
          The Smart MedBox is made up of birchply with 30x20x8.5 cm size and is
          designed to cover broad spectrum of utilization. It is elegantly
          designed to hold medicine in various formats e pills, small size
          medicine boxes, vials, syringes, ointment tube, small powder packets
          etc.,. All the medicines are physically visible hence easy to identify
          their quantity for refilling.
        </Typography>
        <Typography variant='h5' component='h5'>
          Audio Reminder Alarms are designed to draw the attention of the user
          with number of rings control and snooze time control The MedBox is
          equipped with LED indications in all the 6 chambers for picking the
          correct scheduled medicine when Alarm goes ON.{' '}
        </Typography>
      </Grid>
      <Grid
        item
        xs={12}
        md={6}
        className='grid-item'
        sx={{ display: { xs: 'block', md: 'none' } }}
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
        className='colored-section text-wrapper grid-item'
      >
        <Typography variant='h4' component='h4'>
          Application
        </Typography>

        <Typography variant='h5' component='h5'>
          It is designed in a most simplistic way to provide ease of use by
          anyone conversant with mobile operation. Individual slots of the Box
          can be enabled or disabled based on Requirement. Medicine can be
          scheduled either on daily basis or a specific day in a week for a
          specific time.
        </Typography>
        <Typography variant='h5' component='h5'>
          Medicine names can also be stored in the Box for display on Electronic
          display provided on the top of the Box. Medicine names can also be
          stored in the Box for display on Electronic display provided on the
          top of the Box.
        </Typography>
      </Grid>
      <Grid item xs={12} md={6} className='grid-item'>
        <img
          src='https://img.freepik.com/free-photo/medication-time-with-clipboard_23-2148550938.jpg'
          alt=''
        />
      </Grid>
      <Grid item xs={12} marginTop={5}>
        <Divider>
          <Typography variant='h3'>Our Team</Typography>
        </Divider>
      </Grid>
      <Grid item xs={12} md={6}>
        <TeamMember
          name='Omar Sobhy'
          image={omarSobhy}
          position='Software Engineer - Team Leader'
        />
      </Grid>
      <Grid item xs={12} md={6}>
        <TeamMember
          name='Ahmed Hafez'
          image={ahmedHafez}
          position='Electronics Engineer'
        />
      </Grid>
      <Grid item xs={12} md={6}>
        <TeamMember
          name='Abdulrahman Ismael'
          image={abdulrahmanMohammed}
          position='Web Developer'
        />
      </Grid>
      <Grid item xs={12} md={6}>
        <TeamMember
          name='Mohammed Ashraf'
          image={mohamedAshraf}
          position='Web Developer'
        />
      </Grid>
      <Grid item xs={12}>
        <TeamMember
          name='Islam AbouElmagd'
          image={profileImage}
          position='AI Developer'
        />
      </Grid>
    </Grid>
  );
}
